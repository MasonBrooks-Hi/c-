#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> ps(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x; cin >> x;
            a[i][j] = x;
            ps[i][j] = ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1] + x;
        }
    }
    long long ans = 0;
    int K = (n < m ? n : m);
    for (int k = 2; k <= K; k++) {
        for (int i = 1; i + k - 1 <= n; i++) {
            for (int j = 1; j + k - 1 <= m; j++) {
                int r2 = i + k - 1, c2 = j + k - 1;
                int black = ps[r2][c2] - ps[i - 1][c2] - ps[r2][j - 1] + ps[i - 1][j - 1];
                int total = k * k;
                if (abs(2 * black - total) <= 1) ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
