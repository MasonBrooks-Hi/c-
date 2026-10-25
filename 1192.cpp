#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (int i = 0; i < n; i++) cin >> g[i];
    int di[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dj[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '*') {
                cout << '*';
            } else {
                int cnt = 0;
                for (int d = 0; d < 8; d++) {
                    int ni = i + di[d], nj = j + dj[d];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && g[ni][nj] == '*')
                        cnt++;
                }
                cout << cnt;
            }
        }
        cout << endl;
    }
    return 0;
}
