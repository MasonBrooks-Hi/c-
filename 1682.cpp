// 1682 求满足条件的 3 位数：完全平方数且至少有 2 位数字相同
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> ans;
    for (int k = 10; k * k <= 999; k++) {
        int v = k * k;
        int d[3] = {v / 100, (v / 10) % 10, v % 10};
        if (d[0] == d[1] || d[1] == d[2] || d[0] == d[2]) ans.push_back(v);
    }

    if (n >= 1 && n <= (int)ans.size()) cout << ans[n - 1] << "\n";
    return 0;
}
