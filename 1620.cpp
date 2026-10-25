// 1620 机器分配
// 分组(公司)背包 + 字典序最小的最优解恢复
// dp[i][m] = 只考虑第 i..N 个公司、至多使用 m 台设备时的最大盈利
// 恢复时按公司编号从小到大，每次选择使最优值仍然成立的最小台数，
// 从而得到字典序最小的分配方案。
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<vector<long long>> val(n + 1, vector<long long>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> val[i][j];
    }

    vector<vector<long long>> dp(n + 2, vector<long long>(m + 1, 0));
    for (int i = n; i >= 1; i--) {
        for (int cap = 0; cap <= m; cap++) {
            long long best = 0;
            for (int k = 0; k <= cap; k++) {
                best = max(best, val[i][k] + dp[i + 1][cap - k]);
            }
            dp[i][cap] = best;
        }
    }

    cout << dp[1][m] << "\n";

    int rest = m;
    for (int i = 1; i <= n; i++) {
        int take = 0;
        for (int k = 0; k <= rest; k++) {
            if (val[i][k] + dp[i + 1][rest - k] == dp[i][rest]) {
                take = k;
                break;
            }
        }
        cout << i << " " << take << "\n";
        rest -= take;
    }
    return 0;
}
