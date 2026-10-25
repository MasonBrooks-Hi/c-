// 1648 滑雪
// 记忆化搜索：f(x,y) = 从 (x,y) 出发的最长下滑长度（经过点数）
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int R, C;
vector<vector<int>> h;
vector<vector<int>> memo;

int dfs(int x, int y) {
    if (memo[x][y]) return memo[x][y];
    int best = 1;
    const int dx[4] = {-1, 1, 0, 0};
    const int dy[4] = {0, 0, -1, 1};
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
        if (h[nx][ny] < h[x][y]) {
            best = max(best, dfs(nx, ny) + 1);
        }
    }
    return memo[x][y] = best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> R >> C)) return 0;
    h.assign(R, vector<int>(C));
    memo.assign(R, vector<int>(C, 0));
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> h[i][j];

    int ans = 0;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            ans = max(ans, dfs(i, j));

    cout << ans << "\n";
    return 0;
}
