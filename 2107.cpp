#include <iostream>
#include <algorithm>
using namespace std;

long long dp[5005];

int main() {
    int N;
    if (!(cin >> N)) return 0;
    int a[55], total = 0;
    for (int i = 0; i < N; i++) { cin >> a[i]; total += a[i]; }
    if (total % 2 != 0) { cout << 0 << '\n'; return 0; }
    int target = total / 2;
    for (int i = 0; i <= target; i++) dp[i] = 0;
    dp[0] = 1;
    for (int i = 0; i < N; i++)
        for (int j = target; j >= a[i]; j--)
            dp[j] += dp[j - a[i]];
    cout << dp[target] / 2 << '\n';
    return 0;
}
