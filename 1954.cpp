#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    long long n;
    if (!(cin >> n)) return 0;
    double leftover;
    cin >> leftover;
    const double CLEAR = 0.6 * 30; // 绿灯 30 秒，疏通 0.6 辆/秒 => 18 辆/周期
    for (long long i = 0; i < n; i++) {
        double red, green;
        cin >> red >> green;
        double q = leftover + red + green;
        leftover = (q > CLEAR) ? q - CLEAR : 0.0;
    }
    printf("%lld\n", (long long)(leftover + 0.5));
    return 0;
}
