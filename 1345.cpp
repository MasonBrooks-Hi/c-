#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int M, N;
        cin >> M >> N;
        vector<vector<long long>> dp(M + 1, vector<long long>(N + 1, 0));
        for (int j = 0; j <= N; j++) dp[0][j] = 1;
        for (int i = 1; i <= M; i++) dp[i][1] = 1;
        for (int i = 1; i <= M; i++)
            for (int j = 2; j <= N; j++) {
                dp[i][j] = dp[i][j - 1];
                if (i >= j) dp[i][j] += dp[i - j][j];
            }
        cout << dp[M][N] << "\n";
    }
    return 0;
}
