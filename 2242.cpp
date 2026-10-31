#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[505];
int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<int> enemy(n + 1);
    for (int i = 1; i <= n; i++) { cin >> enemy[i]; parent[i] = i; }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        int ru = find(u), rv = find(v);
        if (ru != rv) parent[ru] = rv;
    }
    vector<vector<int>> comps;
    for (int i = 1; i <= n; i++) {
        int r = find(i);
        bool found = false;
        for (auto& c : comps) if (c[0] == r) { c.push_back(i); found = true; break; }
        if (!found) { vector<int> c; c.push_back(r); c.push_back(i); comps.push_back(c); }
    }
    struct Info { vector<int> nodes; int size; long long sum; };
    vector<Info> infos;
    for (auto& c : comps) {
        Info info;
        for (size_t i = 1; i < c.size(); i++) info.nodes.push_back(c[i]);
        sort(info.nodes.begin(), info.nodes.end());
        info.size = info.nodes.size();
        info.sum = 0;
        for (int v : info.nodes) info.sum += enemy[v];
        infos.push_back(info);
    }
    Info bestSize = infos[0], bestSum = infos[0];
    for (auto& info : infos) {
        if (info.size > bestSize.size) bestSize = info;
        else if (info.size == bestSize.size && info.nodes < bestSize.nodes) bestSize = info;
        if (info.sum > bestSum.sum) bestSum = info;
        else if (info.sum == bestSum.sum && info.nodes < bestSum.nodes) bestSum = info;
    }
    for (size_t i = 0; i < bestSize.nodes.size(); i++) {
        if (i) cout << " ";
        cout << bestSize.nodes[i];
    }
    cout << "\n";
    for (size_t i = 0; i < bestSum.nodes.size(); i++) {
        if (i) cout << " ";
        cout << bestSum.nodes[i];
    }
    cout << "\n";
    return 0;
}
