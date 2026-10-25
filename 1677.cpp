// 1677 数制转换
// 输入 a n b：n 是 a 进制数（可能含大小写字母），转成 b 进制输出（字母大写）。
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int digitValue(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'z') return c - 'a' + 10;
    if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    string n;
    if (!(cin >> a >> n >> b)) return 0;

    long long value = 0;
    for (char ch : n) {
        int d = digitValue(ch);
        if (d < 0) continue;
        value = value * a + d;
    }

    const char DIGITS[] = "0123456789ABCDEF";
    if (value == 0) {
        cout << "0\n";
        return 0;
    }
    string out;
    while (value > 0) {
        out += DIGITS[value % b];
        value /= b;
    }
    reverse(out.begin(), out.end());
    cout << out << "\n";
    return 0;
}
