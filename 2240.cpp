#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

const int INF = 2e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<string> g(n);
    int sr = -1, sc = -1, ar = -1, ac = -1;
    for (int i = 0; i < n; i++) {
        cin >> g[i];
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'r') { sr = i; sc = j; }
            if (g[i][j] == 'a') { ar = i; ac = j; }
        }
    }
    vector<vector<int>> dist(n, vector<int>(m, INF));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[sr][sc] = 0;
    pq.push({0, sr * m + sc});
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while (!pq.empty()) {
        int d = pq.top().first, u = pq.top().second;
        pq.pop();
        int r = u / m, c = u % m;
        if (d > dist[r][c]) continue;
        if (r == ar && c == ac) { cout << d << "\n"; return 0; }
        for (int k = 0; k < 4; k++) {
            int nr = r + dir[k][0], nc = c + dir[k][1];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if (g[nr][nc] == '#') continue;
            int w = (g[nr][nc] == 'x') ? 2 : 1;
            if (dist[r][c] + w < dist[nr][nc]) {
                dist[nr][nc] = dist[r][c] + w;
                pq.push({dist[nr][nc], nr * m + nc});
            }
        }
    }
    cout << "NO ANSWER\n";
    return 0;
}
