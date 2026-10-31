#include <iostream>
#include <algorithm>
using namespace std;

int c[11];
int dp[1000005];

int main() {
    for (int i = 1; i <= 10; i++) cin >> c[i];
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        dp[i] = 1e9;
        for (int j = 1; j <= 10 && j <= i; j++)
            dp[i] = min(dp[i], dp[i - j] + c[j]);
    }
    cout << dp[n] << '\n';
    return 0;
}
