#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

const long long INF = 1e18;
long long dp[55][55];

int main() {
    int n, s, b;
    if (!(cin >> n >> s >> b)) return 0;
    for (int i = 0; i <= s; i++)
        for (int j = 0; j <= b; j++) dp[i][j] = INF;
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        long long si, bi, ci;
        cin >> si >> bi >> ci;
        long long cost = 2 * ci;
        for (int a = s; a >= 0; a--)
            for (int bb = b; bb >= 0; bb--) {
                long long na = a + si; if (na > s) na = s;
                long long nb = bb + bi; if (nb > b) nb = b;
                if (dp[a][bb] + cost < dp[na][nb])
                    dp[na][nb] = dp[a][bb] + cost;
            }
    }
    cout << dp[s][b] << '\n';
    return 0;
}
