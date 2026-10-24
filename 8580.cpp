#include <iostream>
#include <cmath> // 引入数学工具箱
using namespace std;

int main() {
    long long x, y;
    cin >> x >> y;
    
    // 直接一步到位：计算 x 的 y 次方，扔给 xxx
    long long xxx = pow(x, y); 
    
    cout << xxx << endl;
    return 0;
}
