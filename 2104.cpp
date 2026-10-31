#include <iostream>
#include <algorithm>
using namespace std;

// River crossing: sort additional times ascending, DP over batches.
int main() {
    int N, M;
    if (!(cin >> N >> M)) return 0;
    int add[2505];
    for (int i = 1; i <= N; i++) cin >> add[i];
    sort(add + 1, add + N + 1);
    // m[c] = time to cross with c cows = M + sum of c smallest add
    // dp[i] = min time to get i cows across
    int dp[2505];
    dp[0] = 0;
    for (int i = 1; i <= N; i++) {
        dp[i] = 1e9;
        int sum = 0;
        for (int j = 1; j <= i; j++) {
            sum += add[j];
            int cross = M + sum;
            int prev = dp[i - j];
            int val = prev + cross + (i < N ? M : 0);
            if (val < dp[i]) dp[i] = val;
        }
    }
    cout << dp[N] << '\n';
    return 0;
}
