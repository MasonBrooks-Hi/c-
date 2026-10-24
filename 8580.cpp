#include <iostream>
#include <cmath> // 使用 pow 函数需要引入这个头文件
using namespace std;

int main() {
    long long x, y;
    cin >> x >> y;
    
    // pow(x, y) 计算 x 的 y 次方，强制转换为 long long 防止溢出
    long long result = pow(x, y);
    
    cout << result << endl;
    return 0;
}
