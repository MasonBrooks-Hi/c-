#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    double r;
    cin >> r;
    
    // 先把分子全部乘起来，最后再除以 3
    // 这样你就绝对不会犯“整数除法”的错误了！
    double v = (4 * 3.14 * r * r * r) / 3.0;
    
    printf("%.2f", v);
    return 0;
}
