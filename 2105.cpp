#include <iostream>
#include <algorithm>
using namespace std;

int dp[1005][35];

int main() {
    int T, W;
    if (!(cin >> T >> W)) return 0;
    for (int t = 1; t <= T; t++) {
        int a;
        cin >> a;
        for (int w = 0; w <= W; w++) {
            int pos = (w % 2 == 0) ? 1 : 2;
            int take = (a == pos) ? 1 : 0;
            int best = dp[t - 1][w];
            if (w > 0 && dp[t - 1][w - 1] > best) best = dp[t - 1][w - 1];
            dp[t][w] = best + take;
        }
    }
    int ans = 0;
    for (int w = 0; w <= W; w++) if (dp[T][w] > ans) ans = dp[T][w];
    cout << ans << '\n';
    return 0;
}
