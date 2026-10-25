#include <iostream>
using namespace std;

int main() {
    long long n;
    if (!(cin >> n)) return 0;
    long long s = 0;
    if (n % 2 == 1) {
        // 奇数：求 1..n 中所有偶数之和
        long long m = n - 1; // 最大偶数
        s = (m / 2) * (m / 2 + 1); // 2*(1+2+...+m/2)
    } else {
        // 偶数：求所有因数之和（含 1 和本身）
        for (long long i = 1; i <= n; i++)
            if (n % i == 0) s += i;
    }
    cout << s << '\n';
    return 0;
}
