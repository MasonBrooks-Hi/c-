#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int a[105];
int dp[105][55];

int main() {
    int N, K;
    if (!(cin >> N >> K)) return 0;
    for (int i = 1; i <= N; i++) cin >> a[i];
    int pairs = K + 3;
    if (2 * pairs > N) { cout << -1 << '\n'; return 0; }
    sort(a + 1, a + N + 1);
    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= pairs; j++) dp[i][j] = INT_MAX / 2;
    for (int i = 0; i <= N; i++) dp[i][0] = 0;
    for (int i = 2; i <= N; i++) {
        int d = (a[i] - a[i - 1]) * (a[i] - a[i - 1]);
        for (int j = 1; j <= pairs; j++) {
            dp[i][j] = dp[i - 1][j];
            if (dp[i - 2][j - 1] + d < dp[i][j])
                dp[i][j] = dp[i - 2][j - 1] + d;
        }
    }
    cout << dp[N][pairs] << '\n';
    return 0;
}
