#include <iostream>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int a[100][100], b[100][100], c[100][100];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> a[i][j];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < k; j++) cin >> b[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++) {
            c[i][j] = 0;
            for (int t = 0; t < m; t++) c[i][j] += a[i][t] * b[t][j];
        }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            if (j) cout << ' ';
            cout << c[i][j];
        }
        cout << endl;
    }
    return 0;
}
