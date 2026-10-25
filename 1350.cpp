#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int m, n;
    if (!(cin >> m >> n)) return 0;
    vector<int> d(m - 1);
    for (int i = 0; i < m - 1; i++) cin >> d[i];
    vector<int> pos(m + 1, 0);
    for (int i = 2; i <= m; i++) pos[i] = pos[i - 1] + d[i - 2];

    // cost[i][j]: min total distance if one school placed optimally among villages i..j
    vector<vector<long long>> cost(m + 1, vector<long long>(m + 1, 0));
    for (int i = 1; i <= m; i++)
        for (int j = i; j <= m; j++) {
            int mid = (i + j) / 2;
            long long s = 0;
            for (int k = i; k <= j; k++)
                s += abs(pos[k] - pos[mid]);
            cost[i][j] = s;
        }

    // dp[i][j]: min cost placing j schools among first i villages
    vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, LLONG_MAX));
    for (int i = 1; i <= m; i++) dp[i][1] = cost[1][i];
    for (int i = 1; i <= m; i++)
        for (int j = 2; j <= n; j++)
            for (int p = j - 1; p < i; p++)
                if (dp[p][j - 1] != LLONG_MAX)
                    dp[i][j] = min(dp[i][j], dp[p][j - 1] + cost[p + 1][i]);

    cout << dp[m][n] << "\n";
    return 0;
}
