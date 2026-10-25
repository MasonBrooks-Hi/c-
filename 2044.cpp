#include <iostream>
using namespace std;

int main() {
    // S = 1+2+4+7+11+16+...（a(k)=1+k(k-1)/2），求 S 首次 >= 5000 时的值
    long long s = 0, a = 1;
    for (long long k = 1;; k++) {
        s += a;
        if (s >= 5000) break;
        a += k; // 下一项
    }
    cout << s << '\n';
    return 0;
}
