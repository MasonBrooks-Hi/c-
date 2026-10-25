// 1876 奶牛式乘法
// A*B = (sum of digits of A) * (sum of digits of B).
#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    long long a, b;
    if (!(cin >> a >> b)) return 0;
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    long long sa = 0, sb = 0;
    while (a) { sa += a % 10; a /= 10; }
    while (b) { sb += b % 10; b /= 10; }
    printf("%lld\n", sa * sb);
    return 0;
}
