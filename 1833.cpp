// 1833 求阿姆斯特朗数
// 3-digit numbers equal to sum of cubes of digits: 153, 370, 371, 407.
#include <cstdio>
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int cnt = 0;
    int cand[4] = {153, 370, 371, 407};
    for (int i = 0; i < 4; i++) if (cand[i] <= n) cnt++;
    printf("%d\n", cnt);
    return 0;
}
