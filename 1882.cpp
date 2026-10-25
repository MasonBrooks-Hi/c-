// 1882 螺旋方阵
// n x n spiral filled 1..n^2 clockwise from top-left.
#include <cstdio>
#include <cstring>
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    static int a[16][16];
    memset(a, 0, sizeof(a));
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    int num = 1;
    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++) a[top][j] = num++;
        top++;
        for (int i = top; i <= bottom; i++) a[i][right] = num++;
        right--;
        if (top <= bottom) {
            for (int j = right; j >= left; j--) a[bottom][j] = num++;
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--) a[i][left] = num++;
            left++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d%c", a[i][j], j == n - 1 ? '\n' : ' ');
    }
    return 0;
}
