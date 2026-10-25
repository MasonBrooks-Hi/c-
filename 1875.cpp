// 1875 喝醉的狱卒
// Cell k toggled once per divisor; open at end iff k is a perfect square.
#include <cstdio>
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int cnt = 0;
    for (long long i = 1; i * i <= n; i++) cnt++;
    printf("%d\n", cnt);
    return 0;
}
