#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    if (!(cin >> n)) return 0;
    vector<vector<int>> c(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> c[i][j];
    vector<int> dp(1 << n, 1e9);
    dp[0] = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        int k = __builtin_popcount(mask) - 1; // person k (0-indexed)
        for (int j = 0; j < n; j++) {
            if (mask & (1 << j)) {
                int prev = mask ^ (1 << j);
                if (dp[prev] + c[k][j] < dp[mask]) dp[mask] = dp[prev] + c[k][j];
            }
        }
    }
    cout << dp[(1 << n) - 1] << "\n";
    return 0;
}
