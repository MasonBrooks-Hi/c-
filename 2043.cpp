#include <iostream>
using namespace std;

int main() {
    // 一堆 100 多个的零件：n%3==2, n%5==3, n%7==5 的最小数（100~200）
    for (int i = 100; i <= 200; i++) {
        if (i % 3 == 2 && i % 5 == 3 && i % 7 == 5) {
            cout << i << '\n';
            break;
        }
    }
    return 0;
}
