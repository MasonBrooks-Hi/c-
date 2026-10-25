// 1830 求n个数的最大值和最小值
// Read integers until one is <0 or >32767. Print max min (or "0 0").
#include <cstdio>
int main() {
    int x;
    bool has = false;
    int mx = -1, mn = 1000000000;
    while (scanf("%d", &x) == 1) {
        if (x < 0 || x > 32767) break;
        has = true;
        if (x > mx) mx = x;
        if (x < mn) mn = x;
    }
    if (!has) printf("0 0\n");
    else printf("%d %d\n", mx, mn);
    return 0;
}
