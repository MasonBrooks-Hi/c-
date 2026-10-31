#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    if (!(cin >> n >> m >> k)) return 0;
    vector<int> X(n), Y(n);
    for (int i = 0; i < n; i++) cin >> X[i] >> Y[i];
    vector<bool> hasPipe(n + 1, false);
    vector<int> Lp(n + 1, 0), Hp(n + 1, 0);
    for (int i = 0; i < k; i++) {
        int P, l, h;
        cin >> P >> l >> h;
        hasPipe[P] = true;
        Lp[P] = l; Hp[P] = h;
    }
    vector<int> dp(m + 1, INF), nxt(m + 1, INF);
    for (int j = 1; j <= m; j++) dp[j] = 0;
    int pipesPassed = 0;
    for (int i = 1; i <= n; i++) {
        int xv = X[i - 1], yv = Y[i - 1];
        fill(nxt.begin(), nxt.end(), INF);
        // rise
        for (int r = 1; r <= xv; r++) {
            vector<int> a;
            for (int h = r; h <= m - 1; h += xv) a.push_back(h);
            int len = a.size();
            int prefMin = INF;
            for (int t = 0; t < len; t++) {
                if (t >= 1 && dp[a[t]] != INF) {
                    int val = prefMin + t;
                    if (val < nxt[a[t]]) nxt[a[t]] = val;
                }
                if (dp[a[t]] != INF) {
                    int cand = dp[a[t]] - t;
                    if (cand < prefMin) prefMin = cand;
                }
            }
        }
        // clamp to m
        for (int p = 1; p <= m; p++) {
            if (dp[p] == INF) continue;
            int kk = (p == m) ? 1 : (m - p + xv - 1) / xv;
            if (kk < 1) kk = 1;
            int val = dp[p] + kk;
            if (val < nxt[m]) nxt[m] = val;
        }
        // fall
        for (int p = 1; p <= m; p++) {
            if (dp[p] == INF) continue;
            int nh = p - yv;
            if (nh >= 1 && nxt[nh] > dp[p]) nxt[nh] = dp[p];
        }
        dp = nxt;
        // pipe mask
        if (hasPipe[i]) {
            bool alive = false;
            for (int j = 1; j <= m; j++) {
                if (j <= Lp[i] || j >= Hp[i]) dp[j] = INF;
                else if (dp[j] < INF) alive = true;
            }
            if (alive) pipesPassed++;
        }
    }
    int best = INF;
    bool done = false;
    for (int j = 1; j <= m; j++) if (dp[j] < INF) { done = true; if (dp[j] < best) best = dp[j]; }
    if (done) cout << 1 << "\n" << best << "\n";
    else cout << 0 << "\n" << pipesPassed << "\n";
    return 0;
}
