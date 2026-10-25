// 1850 二进制中的1
// Print positions (0-based from LSB) of set bits, one per line.
#include <cstdio>
int main() {
    long long n;
    if (scanf("%lld", &n) != 1) return 0;
    for (int i = 0; n > 0; i++, n >>= 1)
        if (n & 1) printf("%d\n", i);
    return 0;
}
