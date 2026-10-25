#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    for (int s = 1; s * s <= n; s++) {
        int sq = s * s;
        for (int i = sq; i <= n; i++)
            dp[i] += dp[i - sq];
    }
    cout << dp[n] << "\n";
    return 0;
}
