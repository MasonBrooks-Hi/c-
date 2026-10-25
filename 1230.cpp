#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int m, n;
    if (!(cin >> m >> n)) return 0;
    if (n < 0 || n > m) {
        cout << 0 << "\n";
        return 0;
    }
    vector<vector<long long>> c(m + 1, vector<long long>(n + 1, 0));
    for (int i = 0; i <= m; i++) {
        c[i][0] = 1;
        if (i <= n) c[i][i] = 1;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= min(i, n); j++) {
            if (j == i) c[i][j] = 1;
            else c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
    cout << c[m][n] << "\n";
    return 0;
}
