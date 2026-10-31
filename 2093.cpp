#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    if (!(cin >> s)) return 0;
    int dig[9], idx = 0;
    for (char c : s)
        if (c >= '0' && c <= '9') dig[idx++] = c - '0';
    int sum = 0;
    for (int i = 0; i < 9; i++) sum += dig[i] * (i + 1);
    int chk = sum % 11;
    char ch = (chk == 10) ? 'X' : ('0' + chk);
    char given = s[s.size() - 1];
    if (given == ch) cout << "Right" << '\n';
    else {
        string r = s;
        r[r.size() - 1] = ch;
        cout << r << '\n';
    }
    return 0;
}
