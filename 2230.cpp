#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    if (!(cin >> N)) return 0;
    vector<int> coins = {6, 13, 15, 20};
    vector<int> dp(N + 1, -1);
    vector<int> prev(N + 1, 0);
    dp[0] = 0;
    for (int x = 1; x <= N; x++) {
        for (int c : coins) {
            if (x >= c && dp[x - c] != -1) {
                if (dp[x - c] + 1 > dp[x]) {
                    dp[x] = dp[x - c] + 1;
                    prev[x] = c;
                }
            }
        }
    }
    vector<int> cnt(4, 0);
    if (dp[N] != -1) {
        int x = N;
        while (x > 0) {
            int c = prev[x];
            if (c == 6) cnt[0]++;
            else if (c == 13) cnt[1]++;
            else if (c == 15) cnt[2]++;
            else if (c == 20) cnt[3]++;
            x -= c;
        }
    }
    cout << "6元：" << cnt[0] << " 13元：" << cnt[1] << " 15元：" << cnt[2] << " 20元：" << cnt[3] << "\n";
    return 0;
}
