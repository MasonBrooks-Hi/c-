// 1863 A类多？B类多？
// A类: popcount(1s) > popcount(0s) in the standard binary representation (no leading zeros).
#include <cstdio>
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int a = 0, b = 0;
    for (int i = 1; i <= n; i++) {
        int ones = 0, bits = 0, x = i;
        while (x) { ones += x & 1; bits++; x >>= 1; }
        if (ones > bits - ones) a++;
        else b++;
    }
    printf("%d %d\n", a, b);
    return 0;
}
