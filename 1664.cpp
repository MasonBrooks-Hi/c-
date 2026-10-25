// 1664 哥德巴赫猜想
// 无输入。把 6~100 的每个偶数表示成两个素数之和，第一个加数取最小的。
// 输出格式：n = a+b（等号两边有空格，加号两边无空格）
#include <iostream>
using namespace std;

bool isPrime(int x) {
    if (x < 2) return false;
    for (int d = 2; d * d <= x; d++)
        if (x % d == 0) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int n = 6; n <= 100; n += 2) {
        for (int p = 2; p <= n / 2; p++) {
            if (isPrime(p) && isPrime(n - p)) {
                cout << n << " = " << p << "+" << n - p << "\n";
                break;
            }
        }
    }
    return 0;
}
