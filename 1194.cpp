#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int r, c, n;
    cin >> r >> c >> n;
    vector<string> g(r);
    for (int i = 0; i < r; i++) cin >> g[i];
    int di[4] = {-1, 1, 0, 0};
    int dj[4] = {0, 0, -1, 1};
    for (int day = 0; day < n; day++) {
        vector<string> ng = g;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++) {
                char cur = g[i][j];
                for (int d = 0; d < 4; d++) {
                    int ni = i + di[d], nj = j + dj[d];
                    if (ni < 0 || ni >= r || nj < 0 || nj >= c) continue;
                    char nb = g[ni][nj];
                    if ((nb == 'R' && cur == 'S') ||
                        (nb == 'S' && cur == 'P') ||
                        (nb == 'P' && cur == 'R'))
                        ng[i][j] = nb;
                }
            }
        g = ng;
    }
    for (int i = 0; i < r; i++) cout << g[i] << endl;
    return 0;
}
