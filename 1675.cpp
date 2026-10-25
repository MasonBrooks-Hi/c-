// 1675 转进制（递归实现）
#include <iostream>
using namespace std;

const char DIGITS[] = "0123456789ABCDEF";

void convert(long long x, int m) {
    if (x >= m) {
        convert(x / m, m);
    }
    cout << DIGITS[x % m];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x;
    int m;
    if (!(cin >> x >> m)) return 0;

    if (x == 0) {
        cout << "0\n";
        return 0;
    }
    if (x < 0) {
        cout << "-";
        x = -x;
    }
    convert(x, m);
    cout << "\n";
    return 0;
}
