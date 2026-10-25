#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int main() {
    int k;
    if (!(cin >> k)) return 0;
    while (k--) {
        int n;
        cin >> n;
        vector<string> g(n);
        for (int i = 0; i < n; i++) cin >> g[i];
        int ha, la, hb, lb;
        cin >> ha >> la >> hb >> lb;
        if (g[ha][la] == '#' || g[hb][lb] == '#') {
            cout << "NO\n";
            continue;
        }
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        queue<pair<int,int>> q;
        q.push({ha, la});
        vis[ha][la] = true;
        bool found = false;
        int di[] = {-1, 1, 0, 0};
        int dj[] = {0, 0, -1, 1};
        while (!q.empty()) {
            auto p = q.front(); q.pop();
            int i = p.first, j = p.second;
            if (i == hb && j == lb) { found = true; break; }
            for (int d = 0; d < 4; d++) {
                int ni = i + di[d], nj = j + dj[d];
                if (ni >= 0 && ni < n && nj >= 0 && nj < n && !vis[ni][nj] && g[ni][nj] == '.') {
                    vis[ni][nj] = true;
                    q.push({ni, nj});
                }
            }
        }
        cout << (found ? "YES" : "NO") << "\n";
    }
    return 0;
}
