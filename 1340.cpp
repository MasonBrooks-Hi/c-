#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m, cx, cy;
    if (cin >> n >> m >> cx >> cy) {
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
        vector<vector<bool>> block(n + 1, vector<bool>(m + 1, false));
        block[cx][cy] = true;
        int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
        int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
        for (int i = 0; i < 8; ++i) {
            int nx = cx + dx[i], ny = cy + dy[i];
            if (nx >= 0 && nx <= n && ny >= 0 && ny <= m) block[nx][ny] = true;
        }
        dp[0][0] = block[0][0] ? 0 : 1;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (block[i][j]) { dp[i][j] = 0; continue; }
                if (i == 0 && j == 0) continue;
                long long v = 0;
                if (i > 0) v += dp[i - 1][j];
                if (j > 0) v += dp[i][j - 1];
                dp[i][j] = v;
            }
        }
        cout << dp[n][m] << endl;
    }
    return 0;
}
