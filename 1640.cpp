// 1640 装箱问题
// 0-1 背包：求不超过容量 V 的最大占用体积，答案为 V - 最大占用体积。
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, n;
    if (!(cin >> v)) return 0;
    cin >> n;
    vector<int> dp(v + 1, 0);
    for (int i = 0; i < n; i++) {
        int vol;
        cin >> vol;
        for (int j = v; j >= vol; j--) {
            dp[j] = max(dp[j], dp[j - vol] + vol);
        }
    }
    cout << v - dp[v] << "\n";
    return 0;
}
