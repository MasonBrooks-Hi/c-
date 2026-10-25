// 1669 质数的和与积
// S = p + q，取乘积最大即让 p 尽可能接近 S/2。
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

    int s;
    if (!(cin >> s)) return 0;

    for (int p = s / 2; p >= 2; p--) {
        if (isPrime(p) && isPrime(s - p)) {
            cout << (long long)p * (s - p) << "\n";
            break;
        }
    }
    return 0;
}
