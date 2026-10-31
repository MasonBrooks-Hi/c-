#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 10007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    if (!(cin >> n)) return 0;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i++) cin >> w[i];
    long long total = 0;
    int mx = 0;
    for (int u = 1; u <= n; u++) {
        long long sum = 0, sumsq = 0;
        int best1 = 0, best2 = 0;
        for (int v : adj[u]) {
            long long wv = w[v];
            sum = (sum + wv) % MOD;
            sumsq = (sumsq + wv * wv % MOD) % MOD;
            if (wv > best1) { best2 = best1; best1 = wv; }
            else if (wv > best2) { best2 = wv; }
        }
        long long contrib = (sum * sum % MOD - sumsq + MOD) % MOD;
        total = (total + contrib) % MOD;
        if (best2 > 0) mx = max(mx, best1 * best2);
    }
    cout << mx << " " << total % MOD << "\n";
    return 0;
}
