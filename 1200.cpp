#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    int m = 2 * N - 1;
    vector<vector<int>> a(m, vector<int>(m, 0));
    int r = 0, c = m / 2;
    a[r][c] = 1;
    for (int k = 2; k <= m * m; k++) {
        int nr = r - 1, nc = c + 1;
        if (nr < 0) nr = m - 1;
        if (nc >= m) nc = 0;
        if (a[nr][nc] != 0) {
            nr = r + 1;
            nc = c;
        }
        r = nr;
        c = nc;
        a[r][c] = k;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (j) cout << ' ';
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}
