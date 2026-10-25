// 1633 分组背包
// 每组最多选一件，组内物品互斥。
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item { int w, c, g; };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, n, t;
    if (!(cin >> v >> n >> t)) return 0;

    vector<Item> items(n);
    for (int i = 0; i < n; i++) cin >> items[i].w >> items[i].c >> items[i].g;

    vector<long long> dp(v + 1, 0);
    for (int g = 1; g <= t; g++) {
        vector<long long> ndp = dp;      // 该组不选
        for (int i = 0; i < n; i++) {
            if (items[i].g != g) continue;
            for (int j = items[i].w; j <= v; j++) {
                ndp[j] = max(ndp[j], dp[j - items[i].w] + items[i].c);
            }
        }
        dp.swap(ndp);
    }
    cout << dp[v] << "\n";
    return 0;
}
