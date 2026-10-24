#include <iostream>
#include <cstdio>   // 引入这个，是为了能用方便的 printf

using namespace std;

int main() {
    double r;       // 第一步：挖一个叫 r 的坑，用来放半径
    cin >> r;       // 第二步：把键盘输入的数字填进坑里
    
    // 第三步：套公式算体积
    // 电脑很呆，4/3会算成1，所以我们必须写成 4.0/3.0
    double v = 4.0 / 3.0 * 3.14 * r * r * r; 
    
    // 第四步：把结果打印出来。%.2f 就是“保留2位小数”的通关密码
    printf("%.2f", v); 
    
    return 0;
}
