// 1835 打印字母塔
// Row i: (N-i) spaces + letters ('A'+i-1) ... 'A' ... ('A'+i-1)
#include <cstdio>
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) printf(" ");
        for (int j = i; j >= 1; j--) printf("%c", 'A' + j - 1);
        for (int j = 2; j <= i; j++) printf("%c", 'A' + j - 1);
        printf("\n");
    }
    return 0;
}
