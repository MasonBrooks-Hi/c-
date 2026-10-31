#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<long long> t(n + 1);
    for (int i = 1; i <= n; i++) cin >> t[i];
    sort(t.begin() + 1, t.end());
    vector<long long> ps(n + 1, 0);
    for (int i = 1; i <= n; i++) ps[i] = ps[i - 1] + t[i];

    const long long INF = 1e18;
    vector<long long> dp(n + 1, INF);
    vector<long long> dep(n + 1, -INF);
    dp[0] = 0;
    dep[0] = -INF;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            long long D = max(t[i], dep[j] + m);
            long long cost = (long long)(i - j) * D - (ps[i] - ps[j]);
            long long val = dp[j] + cost;
            if (val < dp[i]) {
                dp[i] = val;
                dep[i] = D;
            }
        }
    }
    cout << dp[n] << '\n';
    return 0;
}
