#include <iostream>
using namespace std;

int main() {
    long long n;
    if (!(cin >> n)) return 0;
    // 找到对角线段 d: (d-1)*d/2 < n <= d*(d+1)/2
    long long d = 1;
    while (d * (d + 1) / 2 < n) d++;
    long long idx = n - (d - 1) * d / 2; // 段内位置，从 1 开始
    long long num, den;
    if (d % 2 == 1) {
        // 奇数对角线：分子从 d 递减，分母递增
        num = d - idx + 1;
        den = idx;
    } else {
        // 偶数对角线：分子递增，分母从 d 递减
        num = idx;
        den = d - idx + 1;
    }
    cout << num << '/' << den << '\n';
    return 0;
}
