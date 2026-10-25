// 1864 二进制小数
// Exact decimal fraction simulation: multiply fractional part by 2, m times; output m-th bit.
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    int m;
    if (!(cin >> s >> m)) return 0;
    string f;
    size_t dot = s.find('.');
    if (dot != string::npos) f = s.substr(dot + 1);
    int ans = 0;
    for (int step = 0; step < m; step++) {
        int carry = 0;
        for (int i = (int)f.size() - 1; i >= 0; i--) {
            int d = (f[i] - '0') * 2 + carry;
            f[i] = char('0' + d % 10);
            carry = d / 10;
        }
        int bit = carry;
        if (step == m - 1) ans = bit;
        while (f.size() > 1 && f.back() == '0') f.pop_back();
        if (f == "0") {
            if (step < m - 1) ans = 0;
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}
