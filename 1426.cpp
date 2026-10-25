#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    long long total = 0;
    for (int i = 0; i < n; i++) { cin >> a[i]; total += a[i]; }
    vector<bool> dp(total + 1, false);
    dp[0] = true;
    for (int i = 0; i < n; i++) {
        for (int s = total; s >= a[i]; s--) {
            if (dp[s - a[i]]) dp[s] = true;
        }
    }
    int best = 0;
    for (int s = 0; s <= total / 2; s++)
        if (dp[s]) best = s;
    long long S2 = best, S1 = total - best;
    cout << S1 * S1 - S2 * S2 << "\n";
    return 0;
}
