#include <iostream>
using namespace std;

int main() {
    long long x, y;
    cin >> x >> y;
    
    // 用 long long 存储结果，初始值为 1
    long long result = 1; 
    
    // 循环 y 次，每次都乘以 x
    for (int i = 0; i < y; i++) {
        result *= x;
    }
    
    cout << result << endl;
    return 0;
}
