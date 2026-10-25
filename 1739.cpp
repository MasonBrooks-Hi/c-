// 1739 城堡问题
// Flood fill: cells connect across sides without walls. 1=west,2=north,4=east,8=south.
#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int m, n;
    while (cin >> m >> n) {
        vector<vector<int>> w(m, vector<int>(n));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin >> w[i][j];
        vector<vector<char>> vis(m, vector<char>(n, 0));
        int rooms = 0, best = 0;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (vis[r][c]) continue;
                rooms++;
                int cnt = 0;
                stack<pair<int, int>> st;
                st.push({r, c});
                vis[r][c] = 1;
                while (!st.empty()) {
                    auto [cr, cc] = st.top(); st.pop();
                    cnt++;
                    int v = w[cr][cc];
                    if (!(v & 1) && cc - 1 >= 0 && !vis[cr][cc - 1]) { vis[cr][cc - 1] = 1; st.push({cr, cc - 1}); }
                    if (!(v & 2) && cr - 1 >= 0 && !vis[cr - 1][cc]) { vis[cr - 1][cc] = 1; st.push({cr - 1, cc}); }
                    if (!(v & 4) && cc + 1 < n && !vis[cr][cc + 1]) { vis[cr][cc + 1] = 1; st.push({cr, cc + 1}); }
                    if (!(v & 8) && cr + 1 < m && !vis[cr + 1][cc]) { vis[cr + 1][cc] = 1; st.push({cr + 1, cc}); }
                }
                if (cnt > best) best = cnt;
            }
        }
        printf("%d\n%d\n", rooms, best);
    }
    return 0;
}
