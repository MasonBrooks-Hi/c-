#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m, n, xl, yl, x2, y2;
    if (!(cin >> m >> n >> xl >> yl >> x2 >> y2)) return 0;
    vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
    dp[xl][yl] = 1;
    int moves[4][2] = {{1, 2}, {1, -2}, {2, 1}, {2, -1}};
    for (int x = xl; x <= x2; x++) {
        for (int y = 1; y <= n; y++) {
            if (dp[x][y] == 0) continue;
            for (int k = 0; k < 4; k++) {
                int nx = x + moves[k][0], ny = y + moves[k][1];
                if (nx >= 1 && nx <= m && ny >= 1 && ny <= n) {
                    dp[nx][ny] += dp[x][y];
                }
            }
        }
    }
    cout << dp[x2][y2] << "\n";
    return 0;
}
