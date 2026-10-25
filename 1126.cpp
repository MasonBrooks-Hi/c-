#include <iostream>
using namespace std;
int main() {
    int a[5][5];
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) cin >> a[i][j];
    int m, n;
    cin >> m >> n;
    m--; n--;
    for (int j = 0; j < 5; j++) {
        int t = a[m][j];
        a[m][j] = a[n][j];
        a[n][j] = t;
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (j) cout << " ";
            cout << a[i][j];
        }
        cout << "\n";
    }
    return 0;
}
