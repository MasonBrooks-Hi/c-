#include <iostream>
#include <algorithm>
using namespace std;

int dp[10005];

int main() {
    int M, N;
    if (!(cin >> M >> N)) return 0;
    for (int i = 0; i < N; i++) {
        int p, m;
        cin >> p >> m;
        for (int j = m; j <= M; j++)
            dp[j] = max(dp[j], dp[j - m] + p);
    }
    cout << dp[M] << '\n';
    return 0;
}
