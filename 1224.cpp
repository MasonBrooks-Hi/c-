#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<vector<int>> d(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> d[i][j];
    int N = n;
    const int INF = 1e9;
    vector<vector<int>> dp(1 << N, vector<int>(N + 1, INF));
    dp[1][1] = 0;
    for (int mask = 1; mask < (1 << N); mask++) {
        for (int i = 1; i <= N; i++) {
            if (!(mask & (1 << (i - 1)))) continue;
            if (dp[mask][i] == INF) continue;
            for (int j = 1; j <= N; j++) {
                if (mask & (1 << (j - 1))) continue;
                int nmask = mask | (1 << (j - 1));
                dp[nmask][j] = min(dp[nmask][j], dp[mask][i] + d[i][j]);
            }
        }
    }
    int full = (1 << N) - 1;
    int ans = INF;
    for (int i = 1; i <= N; i++) ans = min(ans, dp[full][i] + d[i][1]);
    cout << ans << "\n";
    return 0;
}
