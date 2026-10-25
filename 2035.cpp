#include <iostream>
using namespace std;

int main() {
    long long n;
    if (!(cin >> n)) return 0;
    // 2 的方幂：大于 0 且二进制只有一位 1（等价于不断除以 2 最后剩 1）
    if (n > 0 && (n & (n - 1)) == 0) cout << "yes\n";
    else cout << "no\n";
    return 0;
}
