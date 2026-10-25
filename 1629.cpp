// 1629 完全背包
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    if (!(cin >> m >> n)) return 0;
    vector<long long> dp(m + 1, 0);
    for (int i = 0; i < n; i++) {
        int wi, ci;
        cin >> wi >> ci;
        for (int j = wi; j <= m; j++) {
            dp[j] = max(dp[j], dp[j - wi] + ci);
        }
    }
    cout << dp[m] << "\n";
    return 0;
}
