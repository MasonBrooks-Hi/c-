#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) c1++;
        else if (a[i] == 2) c2++;
    }
    int c3 = n - c1 - c2;
    // x[i][j]: 区域 i 中值 j 的个数（区域1 应为 1，区域2 应为 2，区域3 应为 3）
    auto regionOf = [&](int pos) { // pos: 0-based
        if (pos < c1) return 1;
        if (pos < c1 + c2) return 2;
        return 3;
    };
    long long x12 = 0, x21 = 0, x23 = 0, x32 = 0, x13 = 0, x31 = 0;
    for (int i = 0; i < n; i++) {
        int r = regionOf(i), v = a[i];
        if (r == 1 && v == 2) x12++;
        else if (r == 1 && v == 3) x13++;
        else if (r == 2 && v == 1) x21++;
        else if (r == 2 && v == 3) x23++;
        else if (r == 3 && v == 1) x31++;
        else if (r == 3 && v == 2) x32++;
    }
    long long ans = min(x12, x21) + min(x23, x32) + min(x13, x31);
    ans += 2 * llabs(x12 - x21); // 剩余三元环，每个需 2 次交换
    cout << ans << '\n';
    return 0;
}
