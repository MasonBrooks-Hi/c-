#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    double r;
    cin >> r;
    
    // 严格按照 4/3 * pi * r^3 的原先步骤来：
    // 唯一的通关密码是：4 后面必须加 .0，变成 4.0/3
    double v = (4.0 / 3) * 3.14 * r * r * r;
    
    printf("%.2f", v);
    return 0;
}
