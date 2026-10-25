#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> a(9, vector<int>(9, 0));
    a[4][4] = m;
    int di[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dj[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int day = 0; day < n; day++) {
        vector<vector<int>> b(9, vector<int>(9, 0));
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++) {
                if (a[i][j] > 0) {
                    b[i][j] += 2 * a[i][j];
                    for (int d = 0; d < 8; d++) {
                        int ni = i + di[d], nj = j + dj[d];
                        if (ni >= 0 && ni < 9 && nj >= 0 && nj < 9)
                            b[ni][nj] += a[i][j];
                    }
                }
            }
        a = b;
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (j) cout << ' ';
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}
