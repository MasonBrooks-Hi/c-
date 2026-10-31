#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int MAXN = 100005;
const int K = 17;

int n;
long long H[MAXN];
int nxtB[MAXN], nxtA[MAXN];
long long distB[MAXN], distA[MAXN];

int up[K + 1][MAXN][2];
long long da[K + 1][MAXN][2], db[K + 1][MAXN][2];
bool valid[K + 1][MAXN][2];
int endturn[K + 1][MAXN][2];

// apply 2^k moves starting at (c, t) -> returns result in r*
struct Res {
    int nc; long long a, b; int nt; bool ok;
};

Res apply(int k, int c, int t) {
    if (!valid[k][c][t]) return { -1, 0, 0, t, false };
    return { up[k][c][t], da[k][c][t], db[k][c][t], endturn[k][c][t], true };
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    if (!(cin >> n)) return 0;
    for (int i = 1; i <= n; i++) cin >> H[i];

    // sweep from east to west
    set<pair<long long, int>> s;
    for (int i = n; i >= 1; i--) {
        if (i < n) s.insert({ H[i + 1], i + 1 });
        vector<pair<long long, int>> cand; // (distance, cityIndex)
        auto it = s.lower_bound({ H[i], i });
        vector<int> order;
        if (it != s.end()) order.push_back(it->second);
        if (it != s.begin()) {
            auto p = prev(it);
            order.push_back(p->second);
        }
        // expand to neighbors of neighbors
        if (it != s.end()) {
            auto it2 = next(it);
            if (it2 != s.end()) order.push_back(it2->second);
        }
        if (it != s.begin()) {
            auto p = prev(it);
            if (p != s.begin()) {
                auto p2 = prev(p);
                order.push_back(p2->second);
            }
        }
        // sort candidates by (dist, height) ascending: nearest first
        vector<pair<pair<long long, long long>, int>> lst;
        for (int cidx : order) {
            long long d = llabs(H[i] - H[cidx]);
            lst.push_back({ { d, H[cidx] }, cidx });
        }
        sort(lst.begin(), lst.end());
        if (lst.empty()) {
            nxtB[i] = 0; nxtA[i] = 0; distB[i] = distA[i] = 0;
        } else {
            nxtB[i] = lst[0].second;
            distB[i] = lst[0].first.first;
            if (lst.size() >= 2) {
                nxtA[i] = lst[1].second;
                distA[i] = lst[1].first.first;
            } else {
                nxtA[i] = 0; distA[i] = 0;
            }
        }
    }

    // build doubling (single move = k=0)
    for (int i = 1; i <= n; i++) {
        for (int t = 0; t < 2; t++) {
            valid[0][i][t] = false;
            if (t == 0) { // A's turn -> 2nd nearest
                if (nxtA[i]) { up[0][i][t] = nxtA[i]; da[0][i][t] = distA[i]; db[0][i][t] = 0; endturn[0][i][t] = 1; valid[0][i][t] = true; }
            } else { // B's turn -> nearest
                if (nxtB[i]) { up[0][i][t] = nxtB[i]; da[0][i][t] = 0; db[0][i][t] = distB[i]; endturn[0][i][t] = 0; valid[0][i][t] = true; }
            }
        }
    }
    for (int k = 1; k <= K; k++) {
        for (int i = 1; i <= n; i++) {
            for (int t = 0; t < 2; t++) {
                valid[k][i][t] = false;
                Res r1 = apply(k - 1, i, t);
                if (!r1.ok) continue;
                Res r2 = apply(k - 1, r1.nc, r1.nt);
                if (!r2.ok) continue;
                up[k][i][t] = r2.nc;
                da[k][i][t] = r1.a + r2.a;
                db[k][i][t] = r1.b + r2.b;
                endturn[k][i][t] = r2.nt;
                valid[k][i][t] = true;
            }
        }
    }

    auto simulate = [&](int start, long long X) -> pair<long long, long long> {
        int c = start, t = 0;
        long long A = 0, B = 0;
        for (int k = K; k >= 1; k--) {
            if (valid[k][c][t] && da[k][c][t] + db[k][c][t] <= X) {
                A += da[k][c][t];
                B += db[k][c][t];
                X -= da[k][c][t] + db[k][c][t];
                c = up[k][c][t];
                t = endturn[k][c][t];
            }
        }
        while (valid[0][c][t] && da[0][c][t] + db[0][c][t] <= X) {
            A += da[0][c][t];
            B += db[0][c][t];
            X -= da[0][c][t] + db[0][c][t];
            c = up[0][c][t];
            t = endturn[0][c][t];
        }
        return { A, B };
    };

    long long X0;
    cin >> X0;
    int M;
    cin >> M;
    // find S0 for X0
    int bestS = -1;
    // comparator: ratio A/B, smaller better; db==0 -> infinity
    auto better = [&](int s1, int s2) -> bool {
        auto p1 = simulate(s1, X0);
        auto p2 = simulate(s2, X0);
        long long a1 = p1.first, b1 = p1.second;
        long long a2 = p2.first, b2 = p2.second;
        bool inf1 = (b1 == 0), inf2 = (b2 == 0);
        if (inf1 && inf2) return H[s1] > H[s2]; // tie: higher H better
        if (inf1) return false; // inf is worse
        if (inf2) return true;
        __int128 l = (__int128)a1 * b2;
        __int128 r = (__int128)a2 * b1;
        if (l != r) return l < r;
        return H[s1] > H[s2];
    };
    for (int s = 1; s <= n; s++) {
        if (bestS == -1) bestS = s;
        else if (better(s, bestS)) bestS = s;
    }
    cout << bestS << "\n";
    for (int i = 0; i < M; i++) {
        int si; long long xi;
        cin >> si >> xi;
        auto p = simulate(si, xi);
        cout << p.first << " " << p.second << "\n";
    }
    return 0;
}
