// 1660 求正整数 2 和 n 之间的完全数
// 完全数：除本身外的因子之和等于本身。
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    bool first = true;
    for (int x = 2; x <= n; x++) {
        // 求除自身以外的所有正因子之和
        int sum = 0;
        for (int d = 1; d * d <= x; d++) {
            if (x % d == 0) {
                sum += d;
                if (d != x / d) sum += x / d;
            }
        }
        sum -= x;   // 去掉自身
        if (sum == x) {
            if (!first) cout << " ";
            cout << x;
            first = false;
        }
    }
    cout << "\n";
    return 0;
}
