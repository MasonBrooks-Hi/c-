// 1632 二维背包_潜水员
// dp[o][n] = 满足“至少 o 升氧、至少 n 升氮”所需气缸的最小总重量
// 用饱和坐标（超出需求时截断到需求值）表示。
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    if (!(cin >> m >> n)) return 0;
    int k;
    cin >> k;

    const long long INF = (1LL << 60);
    vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, INF));
    dp[0][0] = 0;

    for (int i = 0; i < k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        vector<vector<long long>> ndp = dp;   // 不选这个气缸
        for (int o = 0; o <= m; o++) {
            for (int t = 0; t <= n; t++) {
                if (dp[o][t] >= INF) continue;
                int no = min(m, o + a);
                int nt = min(n, t + b);
                ndp[no][nt] = min(ndp[no][nt], dp[o][t] + c);
            }
        }
        dp.swap(ndp);
    }

    cout << dp[m][n] << "\n";
    return 0;
}
