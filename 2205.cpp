#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    if (!(cin >> n >> m >> k)) return 0;
    vector<int> D(n + 1, 0);
    for (int i = 1; i < n; i++) cin >> D[i];
    vector<long long> T(m), A(m), B(m);
    vector<long long> wait(n + 1, 0);
    vector<int> cntB(n + 1, 0);
    for (int i = 0; i < m; i++) {
        cin >> T[i] >> A[i] >> B[i];
        if (T[i] > wait[A[i]]) wait[A[i]] = T[i];
        cntB[B[i]]++;
    }
    vector<long long> pref(n + 1, 0);
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + cntB[i];

    vector<long long> arrive(n + 1, 0);
    auto compute = [&]() {
        arrive[1] = 0;
        for (int i = 1; i < n; i++) {
            long long depart = max(arrive[i], wait[i]);
            arrive[i + 1] = depart + D[i];
        }
    };
    compute();
    long long total = 0;
    for (int i = 0; i < m; i++) total += arrive[B[i]] - T[i];

    while (k > 0) {
        compute();
        // free[x]: arrive[x] >= wait[x] (reduction propagates through x)
        vector<bool> free(n + 1, false);
        for (int x = 1; x <= n; x++) free[x] = (arrive[x] >= wait[x]);
        // nextCap[x] = first station >= x that is NOT free (capped)
        vector<int> nextCap(n + 2, n + 1);
        for (int x = n; x >= 1; x--) {
            if (!free[x]) nextCap[x] = x;
            else nextCap[x] = nextCap[x + 1];
        }
        long long bestBen = 0;
        int bestI = -1;
        for (int i = 1; i < n; i++) {
            if (D[i] <= 0) continue;
            int reach = nextCap[i + 1] - 1; // furthest station shifted
            if (reach <= i) continue;
            long long ben = pref[reach] - pref[i];
            if (ben > bestBen) { bestBen = ben; bestI = i; }
        }
        if (bestI == -1) break;
        D[bestI]--;
        total -= bestBen;
        k--;
    }
    cout << total << "\n";
    return 0;
}
