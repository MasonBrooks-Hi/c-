#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, k;
    if (!(cin >> N >> k)) return 0;
    vector<bool> dp(k, false);
    dp[0] = true;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        x %= k;
        if (x < 0) x += k;
        vector<bool> ndp(k, false);
        for (int r = 0; r < k; r++) {
            if (dp[r]) {
                int a = (r + x) % k;
                int b = (r - x + k) % k;
                ndp[a] = true;
                ndp[b] = true;
            }
        }
        dp = ndp;
    }
    cout << (dp[0] ? "YES" : "NO") << "\n";
    return 0;
}
