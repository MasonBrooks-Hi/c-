// 1649 最长公共子序列2
// 多组数据，读到 EOF。每组两个字符串（长度不超过 200）。
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string x, y;
    while (cin >> x >> y) {
        int n = (int)x.size(), m = (int)y.size();
        vector<int> dp(m + 1, 0);
        for (int i = 1; i <= n; i++) {
            int prev = 0;
            for (int j = 1; j <= m; j++) {
                int tmp = dp[j];
                if (x[i - 1] == y[j - 1]) {
                    dp[j] = prev + 1;
                } else {
                    dp[j] = max(dp[j], dp[j - 1]);
                }
                prev = tmp;
            }
        }
        cout << dp[m] << "\n";
    }
    return 0;
}
