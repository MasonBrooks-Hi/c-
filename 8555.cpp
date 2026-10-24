#include <cstdio>

int main() {
    int a;
    float b;
    double c;

    // 1. 按照 int, float, double 的顺序输入三个数
    // 确保 double 类型使用 %lf
    scanf("%d %f %lf", &a, &b, &c);

    // 2. 按照原顺序输出，中间用空格隔开
    // 默认情况下 %f 会输出 6 位小数
    printf("%d %f %f\n", a, b, c);

    return 0;
}
