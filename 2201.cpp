#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, p;
    if (!(cin >> n >> k >> p)) return 0;
    vector<int> color(n + 1), cost(n + 1);
    for (int i = 1; i <= n; i++) cin >> color[i] >> cost[i];
    vector<int> V;
    for (int i = 1; i <= n; i++) if (cost[i] <= p) V.push_back(i);
    vector<vector<int>> col(k);
    for (int i = 1; i <= n; i++) col[color[i]].push_back(i);
    long long ans = 0;
    for (int c = 0; c < k; c++) {
        auto& pos = col[c];
        for (int i = 0; i < (int)pos.size(); i++) {
            int pv = pos[i];
            auto it = lower_bound(V.begin(), V.end(), pv);
            if (it == V.end()) continue;
            int nextV = *it;
            int idx = lower_bound(pos.begin(), pos.end(), nextV) - pos.begin();
            int fv = max(i + 1, idx);
            ans += pos.size() - fv;
        }
    }
    cout << ans << "\n";
    return 0;
}
