#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    while (cin >> n >> m) {
        vector<vector<int>> adj(n + 1);
        vector<int> indeg(n + 1, 0);
        for (int t = 0; t < m; t++) {
            int s;
            cin >> s;
            vector<int> stops(s);
            int L = n + 1, R = 0;
            for (int i = 0; i < s; i++) {
                cin >> stops[i];
                if (stops[i] < L) L = stops[i];
                if (stops[i] > R) R = stops[i];
            }
            vector<bool> isStop(n + 1, false);
            for (int x : stops) isStop[x] = true;
            for (int y = L; y <= R; y++) {
                if (isStop[y]) continue;
                for (int x : stops) {
                    adj[y].push_back(x);
                    indeg[x]++;
                }
            }
        }
        vector<int> level(n + 1, 1);
        queue<int> q;
        for (int i = 1; i <= n; i++) if (indeg[i] == 0) q.push(i);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (level[v] < level[u] + 1) level[v] = level[u] + 1;
                indeg[v]--;
                if (indeg[v] == 0) q.push(v);
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) if (level[i] > ans) ans = level[i];
        cout << ans << "\n";
    }
    return 0;
}
