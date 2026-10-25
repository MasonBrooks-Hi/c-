// 1873 算算和是多少
// Add a 3-digit number to its digit-reversal.
#include <cstdio>
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int r = 0, t = n;
    while (t) { r = r * 10 + t % 10; t /= 10; }
    printf("%d\n", n + r);
    return 0;
}
