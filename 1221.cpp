#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<vector<bool>> vis;
int sx, sy, ex, ey;
vector<pair<int, int>> path;
bool found = false;
// direction order: left, up, right, down  (x = row, y = col)
int dir[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

void dfs(int x, int y) {
    path.push_back({x, y});
    vis[x][y] = true;
    if (x == ex && y == ey) {
        found = true;
        for (int i = 0; i < (int)path.size(); i++) {
            if (i) cout << "->";
            cout << "(" << path[i].first << "," << path[i].second << ")";
        }
        cout << "\n";
    } else {
        for (int d = 0; d < 4; d++) {
            int nx = x + dir[d][0];
            int ny = y + dir[d][1];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !vis[nx][ny] && g[nx][ny] == 1) {
                dfs(nx, ny);
            }
        }
    }
    vis[x][y] = false;
    path.pop_back();
}

int main() {
    if (!(cin >> n >> m)) return 0;
    g.assign(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> g[i][j];
    cin >> sx >> sy >> ex >> ey;
    dfs(sx, sy);
    if (!found) cout << -1 << "\n";
    return 0;
}
