// 1628 输出背包方案
// 0-1 背包，并用二维表从后往前回溯得到所选物品（按 01 背包思路找到第一种方案）
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<int> w(n), c(n);
    for (int i = 0; i < n; i++) cin >> w[i];
    for (int i = 0; i < n; i++) cin >> c[i];
    int m;
    cin >> m;

    vector<vector<long long>> f(n + 1, vector<long long>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            f[i][j] = f[i - 1][j];
            if (w[i - 1] <= j) {
                f[i][j] = max(f[i][j], f[i - 1][j - w[i - 1]] + c[i - 1]);
            }
        }
    }

    string pick(n, '0');
    int j = m;
    for (int i = n; i >= 1; i--) {
        if (w[i - 1] <= j && f[i][j] == f[i - 1][j - w[i - 1]] + c[i - 1]) {
            pick[i - 1] = '1';
            j -= w[i - 1];
        }
    }

    cout << pick << "\n";
    cout << f[n][m] << "\n";
    return 0;
}
