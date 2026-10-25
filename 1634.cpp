// 1634 货币系统
// 完全背包计数：组合数（顺序不计），方案数可能很大，用 long long。
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<long long> dp(m + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        for (int j = v; j <= m; j++) {
            dp[j] += dp[j - v];
        }
    }
    cout << dp[m] << "\n";
    return 0;
}
