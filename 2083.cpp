#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int N = 105;
char g[N][N];
int dist[N][N];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int sx, sy, ex, ey;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> g[i][j];
                dist[i][j] = -1;
                if (g[i][j] == 'S') { sx = i; sy = j; }
                if (g[i][j] == 'E') { ex = i; ey = j; }
            }
        }
        queue<pair<int, int>> q;
        q.push({sx, sy});
        dist[sx][sy] = 0;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (g[nx][ny] == '#') continue;
                if (dist[nx][ny] != -1) continue;
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
        cout << dist[ex][ey] << '\n';
    }
    return 0;
}
