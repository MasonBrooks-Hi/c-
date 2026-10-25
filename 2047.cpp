#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s; // 可能长达 10^60，按字符串读入，只看最后一位
        int last = s.back() - '0';
        cout << (last % 2 == 0 ? "even" : "odd") << '\n';
    }
    return 0;
}
