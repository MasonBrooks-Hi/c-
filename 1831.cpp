// 1831 求满足条件的整数个数
// Count x in [1,n] with x%3==2, x%5==3, x%7==2.
#include <cstdio>
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int cnt = 0;
    for (int x = 1; x <= n; x++)
        if (x % 3 == 2 && x % 5 == 3 && x % 7 == 2) cnt++;
    printf("%d\n", cnt);
    return 0;
}
