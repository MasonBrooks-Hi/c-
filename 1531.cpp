#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m;
    if (!(cin >> m)) return 0;
    int n = 1 << m;
    vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));
    a[1][1] = 1;
    int t = 1;
    while (t < n) {
        for (int i = 1; i <= t; i++)
            for (int j = 1; j <= t; j++)
                a[i + t][j + t] = a[i][j];
        for (int i = 1; i <= t; i++)
            for (int j = 1; j <= t; j++)
                a[i + t][j] = a[i][j] + t;
        for (int i = 1; i <= t; i++)
            for (int j = 1; j <= t; j++)
                a[i][j + t] = a[i + t][j];
        t *= 2;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j > 1) cout << " ";
            cout << a[i][j];
        }
        cout << "\n";
    }
    return 0;
}
