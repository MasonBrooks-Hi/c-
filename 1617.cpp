#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<int> mine(n + 1);
    for (int i = 1; i <= n; i++) cin >> mine[i];
    vector<vector<int>> adj(n + 1);
    int x, y;
    while (cin >> x >> y && (x != 0 || y != 0)) adj[x].push_back(y);
    vector<int> dp(n + 1, 0), prev(n + 1, 0);
    for (int i = 1; i <= n; i++) dp[i] = mine[i];
    for (int i = 1; i <= n; i++) {
        for (int j : adj[i]) {
            if (dp[i] + mine[j] > dp[j]) {
                dp[j] = dp[i] + mine[j];
                prev[j] = i;
            }
        }
    }
    int best = 1;
    for (int i = 2; i <= n; i++)
        if (dp[i] > dp[best]) best = i;
    vector<int> path;
    for (int cur = best; cur != 0; cur = prev[cur]) path.push_back(cur);
    reverse(path.begin(), path.end());
    for (size_t i = 0; i < path.size(); i++) {
        if (i) cout << "-";
        cout << path[i];
    }
    cout << "\n" << dp[best] << "\n";
    return 0;
}
