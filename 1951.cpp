#include <iostream>
using namespace std;

int main() {
    long long n;
    if (!(cin >> n)) return 0;
    // 数列: a1=1, a(k)=a(k-1)+(k-1)，即 a(k)=1+k(k-1)/2
    long long sum = 0, a = 1;
    for (long long k = 1; k <= n; k++) {
        sum += a;
        a += k; // 下一项
    }
    cout << sum << '\n';
    return 0;
}
