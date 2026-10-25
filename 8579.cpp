#include <iostream>
#include <cstdio> // 使用 printf 建议加上这个头文件
using namespace std;

int main() {
    int s, f, m;
    
    // 1. 用 cin 简单地读入三个数
    cin >> s >> f >> m;
    
    // 2. 核心计算（保持不变）
    int total_seconds = s * 3600 + f * 60 + m;
    
    // 3. 用 printf 输出整数，%d 会被 total_seconds 的值替换，\n 表示换行
    printf("%d\n", total_seconds);
    
    return 0;
}
