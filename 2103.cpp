#include <iostream>
#include <algorithm>
using namespace std;

int dp[405][405];

int main() {
    int V, M;
    if (!(cin >> V >> M)) return 0;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int v, m, cal;
        cin >> v >> m >> cal;
        for (int a = V; a >= v; a--)
            for (int b = M; b >= m; b--)
                dp[a][b] = max(dp[a][b], dp[a - v][b - m] + cal);
    }
    cout << dp[V][M] << '\n';
    return 0;
}
