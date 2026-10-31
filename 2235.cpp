#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> primes;
    for (int i = 2; i <= 200; i++) {
        bool p = true;
        for (int j = 2; j * j <= i; j++) if (i % j == 0) { p = false; break; }
        if (p) primes.push_back(i);
    }
    const int MAXN = 200;
    vector<long long> dp(MAXN + 1, 0);
    dp[0] = 1;
    for (int p : primes) {
        for (int i = p; i <= MAXN; i++) dp[i] += dp[i - p];
    }
    int n;
    while (cin >> n) {
        cout << dp[n] << "\n";
    }
    return 0;
}
