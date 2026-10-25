#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, m, sx, sy, ans;
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
bool vis[12][12];

void dfs(int x, int y, int step) {
    if (step == n * m) { ans++; return; }
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]) {
            vis[nx][ny] = true;
            dfs(nx, ny, step + 1);
            vis[nx][ny] = false;
        }
    }
}

int main() {
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        cin >> n >> m >> sx >> sy;
        ans = 0;
        memset(vis, 0, sizeof vis);
        vis[sx][sy] = true;
        dfs(sx, sy, 1);
        cout << ans << "\n";
    }
    return 0;
}
