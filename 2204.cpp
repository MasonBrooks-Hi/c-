#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m;
vector<long long> w, v;
vector<int> L, R;
int maxW = 0;

long long calc(int W) {
    vector<long long> pc(n + 1, 0), ps(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        pc[i] = pc[i - 1] + (w[i] >= W ? 1 : 0);
        ps[i] = ps[i - 1] + (w[i] >= W ? v[i] : 0);
    }
    long long Y = 0;
    for (int i = 0; i < m; i++) {
        long long c = pc[R[i]] - pc[L[i] - 1];
        long long s = ps[R[i]] - ps[L[i] - 1];
        Y += c * s;
    }
    return Y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long S;
    if (!(cin >> n >> m >> S)) return 0;
    w.resize(n + 1); v.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
        if (w[i] > maxW) maxW = w[i];
    }
    L.resize(m); R.resize(m);
    for (int i = 0; i < m; i++) cin >> L[i] >> R[i];
    int lo = 0, hi = maxW + 1, ans = hi;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (calc(mid) <= S) { ans = mid; hi = mid - 1; }
        else lo = mid + 1;
    }
    long long best = llabs(S - calc(ans));
    if (ans > 0) best = min(best, llabs(S - calc(ans - 1)));
    cout << best << "\n";
    return 0;
}
