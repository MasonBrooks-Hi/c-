// 1862 n的阶乘尾部有多少个连续的0
#include <cstdio>
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    long long cnt = 0;
    for (long long p = 5; p <= n; p *= 5) cnt += n / p;
    printf("%lld\n", cnt);
    return 0;
}
