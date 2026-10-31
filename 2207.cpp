#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++) dp[i][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= a[i] && k <= j; k++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % MOD;
            }
        }
    }
    cout << dp[n][m] << "\n";
    return 0;
}
