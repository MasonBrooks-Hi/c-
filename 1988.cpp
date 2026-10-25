#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int w, h;
    if (!(cin >> w >> h)) return 0;
    vector<string> g(h);
    for (int i = 0; i < h; i++) cin >> g[i];
    vector<vector<char>> vis(h, vector<char>(w, 0));
    int best = 0;
    // 迭代 DFS 找最大四连通块
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (g[i][j] != '*' || vis[i][j]) continue;
            int cnt = 0;
            vector<pair<int, int>> st;
            st.push_back({i, j});
            vis[i][j] = 1;
            while (!st.empty()) {
                auto [r, c] = st.back();
                st.pop_back();
                cnt++;
                const int dr[4] = {1, -1, 0, 0};
                const int dc[4] = {0, 0, 1, -1};
                for (int k = 0; k < 4; k++) {
                    int nr = r + dr[k], nc = c + dc[k];
                    if (nr < 0 || nr >= h || nc < 0 || nc >= w) continue;
                    if (g[nr][nc] != '*' || vis[nr][nc]) continue;
                    vis[nr][nc] = 1;
                    st.push_back({nr, nc});
                }
            }
            if (cnt > best) best = cnt;
        }
    }
    cout << best << '\n';
    return 0;
}
