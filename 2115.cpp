#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int a[2005];
int dp[2005][1005];

int main() {
    int n, k;
    while (cin >> n >> k && (n != 0 || k != 0)) {
        for (int i = 1; i <= n; i++) cin >> a[i];
        int pairs = k;
        if (2 * pairs > n) { cout << -1 << '\n'; continue; }
        sort(a + 1, a + n + 1);
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= pairs; j++) dp[i][j] = INT_MAX / 2;
        for (int i = 0; i <= n; i++) dp[i][0] = 0;
        for (int i = 2; i <= n; i++) {
            int d = (a[i] - a[i - 1]) * (a[i] - a[i - 1]);
            for (int j = 1; j <= pairs; j++) {
                dp[i][j] = dp[i - 1][j];
                if (dp[i - 2][j - 1] + d < dp[i][j])
                    dp[i][j] = dp[i - 2][j - 1] + d;
            }
        }
        cout << dp[n][pairs] << '\n';
    }
    return 0;
}
