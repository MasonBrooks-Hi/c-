// 1665 简单算术表达式求值
// 读取一行表达式（运算符前后可能有空格），按整数运算求值。
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int jisuan(int a, char c, int b) {
    switch (c) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return (b == 0) ? 0 : a / b;
        case '%': return (b == 0) ? 0 : a % b;
        default: return 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    while (getline(cin, line)) {
        // 去掉所有空白字符
        string s;
        for (char ch : line)
            if (!isspace((unsigned char)ch)) s += ch;
        if (s.empty()) continue;

        size_t i = 0;
        int sign = 1;
        if (s[i] == '-' || s[i] == '+') { sign = (s[i] == '-') ? -1 : 1; i++; }
        int a = 0;
        while (i < s.size() && isdigit((unsigned char)s[i])) {
            a = a * 10 + (s[i] - '0');
            i++;
        }
        a *= sign;
        if (i >= s.size()) continue;
        char op = s[i++];
        int b = 0;
        while (i < s.size() && isdigit((unsigned char)s[i])) {
            b = b * 10 + (s[i] - '0');
            i++;
        }
        cout << jisuan(a, op, b) << "\n";
    }
    return 0;
}
