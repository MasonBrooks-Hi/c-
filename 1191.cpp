#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[20][20];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> a[i][j];
    int b[20][20];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                b[i][j] = a[i][j];
            } else {
                b[i][j] = (a[i][j] + a[i - 1][j] + a[i + 1][j] +
                           a[i][j - 1] + a[i][j + 1]) / 5;
            }
        }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j) cout << ' ';
            cout << b[i][j];
        }
        cout << endl;
    }
    return 0;
}
