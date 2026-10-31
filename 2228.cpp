#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<vector<int>> adj(n + 1), radj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }
    int s, t;
    cin >> s >> t;
    // R = vertices reachable from t
    vector<bool> reach(n + 1, false);
    queue<int> q;
    q.push(t); reach[t] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : radj[u]) if (!reach[v]) { reach[v] = true; q.push(v); }
    }
    vector<bool> valid(n + 1, false);
    for (int u = 1; u <= n; u++) {
        if (adj[u].empty()) { valid[u] = true; continue; }
        bool ok = true;
        for (int v : adj[u]) if (!reach[v]) { ok = false; break; }
        valid[u] = ok;
    }
    vector<int> dist(n + 1, -1);
    if (valid[s]) {
        queue<int> q2;
        q2.push(s); dist[s] = 0;
        while (!q2.empty()) {
            int u = q2.front(); q2.pop();
            for (int v : adj[u]) {
                if (dist[v] == -1 && valid[v]) {
                    dist[v] = dist[u] + 1;
                    q2.push(v);
                }
            }
        }
    }
    cout << dist[t] << "\n";
    return 0;
}
