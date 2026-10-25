// 1631 混合背包
// p==0 完全背包；p>=1 为多重背包（至多 p 件）。
// 使用二维表，保证多重背包的件数上限严格生效。
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    if (!(cin >> m >> n)) return 0;

    vector<vector<long long>> f(n + 1, vector<long long>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        int wi, ci, pi;
        cin >> wi >> ci >> pi;
        for (int j = 0; j <= m; j++) {
            f[i][j] = f[i - 1][j];
            if (wi > j) continue;
            if (pi == 0) {
                // 完全背包：使用当前行
                f[i][j] = max(f[i][j], f[i][j - wi] + ci);
            } else {
                // 多重背包：最多 pi 件
                for (int k = 1; k <= pi && k * wi <= j; k++) {
                    f[i][j] = max(f[i][j], f[i - 1][j - k * wi] + (long long)k * ci);
                }
            }
        }
    }
    cout << f[n][m] << "\n";
    return 0;
}
