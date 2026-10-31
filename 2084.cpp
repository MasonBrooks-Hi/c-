#include <iostream>
using namespace std;

long long dp[6005];

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;
    for (int i = 0; i < n; i++) {
        int p, v, s;
        cin >> p >> v >> s;
        for (int j = m; j >= p; j--) {
            for (int k = 1; k <= s; k++) {
                if (j - k * p < 0) break;
                if (dp[j - k * p] + (long long)k * v > dp[j])
                    dp[j] = dp[j - k * p] + (long long)k * v;
            }
        }
    }
    cout << dp[m] << '\n';
    return 0;
}
