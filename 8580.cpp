#include <iostream>
using namespace std;

int main() {
    long long x, y;
    cin >> x >> y;
    
    // 把名字改成 xxx，完全可以
    long long xxx = 1; 
    
    for (int i = 0; i < y; i++) {
        xxx *= x; // 每次把结果乘到 xxx 盒子里
    }
    
    cout << xxx << endl; // 最后打印 xxx 盒子里装的数字
    return 0;
}
