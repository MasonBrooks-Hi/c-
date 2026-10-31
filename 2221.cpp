#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 10005;
const int LOG = 15;

struct Edge {
    int u, v, w;
};

int parent[MAXN], depth[MAXN];
int up[LOG][MAXN];
int minE[LOG][MAXN];
vector<pair<int, int>> adj[MAXN]; // (neighbor, weight)

int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

void dfs(int u, int p, int w, int d) {
    up[0][u] = p;
    minE[0][u] = w;
    depth[u] = d;
    for (auto& e : adj[u]) {
        int v = e.first, c = e.second;
        if (v == p) continue;
        dfs(v, u, c, d + 1);
    }
}

int lcaMin(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int ans = 2000000000;
    int diff = depth[u] - depth[v];
    for (int k = 0; k < LOG; k++)
        if (diff & (1 << k)) { ans = min(ans, minE[k][u]); u = up[k][u]; }
    if (u == v) return ans;
    for (int k = LOG - 1; k >= 0; k--) {
        if (up[k][u] != up[k][v]) {
            ans = min(ans, min(minE[k][u], minE[k][v]));
            u = up[k][u];
            v = up[k][v];
        }
    }
    ans = min(ans, min(minE[0][u], minE[0][v]));
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) cin >> edges[i].u >> edges[i].v >> edges[i].w;
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) { return a.w > b.w; });
    for (int i = 1; i <= n; i++) parent[i] = i;
    for (int i = 0; i < m; i++) {
        int ru = find(edges[i].u), rv = find(edges[i].v);
        if (ru != rv) {
            parent[ru] = rv;
            adj[edges[i].u].push_back({edges[i].v, edges[i].w});
            adj[edges[i].v].push_back({edges[i].u, edges[i].w});
        }
    }
    for (int i = 1; i <= n; i++) {
        if (parent[i] == i) dfs(i, 0, 2000000000, 1);
    }
    for (int k = 1; k < LOG; k++) {
        for (int i = 1; i <= n; i++) {
            up[k][i] = up[k - 1][up[k - 1][i]];
            minE[k][i] = min(minE[k - 1][i], minE[k - 1][up[k - 1][i]]);
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        if (find(x) != find(y)) cout << -1 << "\n";
        else cout << lcaMin(x, y) << "\n";
    }
    return 0;
}
