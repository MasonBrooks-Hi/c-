#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;

int prec(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '^') return 3;
    return 0;
}

int main() {
    string s;
    if (!(cin >> s)) return 0;
    vector<string> out;
    vector<char> op;
    int i = 0;
    int len = (int)s.size();
    while (i < len) {
        if (s[i] >= '0' && s[i] <= '9') {
            string num;
            while (i < len && s[i] >= '0' && s[i] <= '9') num += s[i++];
            out.push_back(num);
        } else if (s[i] == '(') {
            op.push_back('(');
            i++;
        } else if (s[i] == ')') {
            while (!op.empty() && op.back() != '(') {
                out.push_back(string(1, op.back()));
                op.pop_back();
            }
            if (!op.empty()) op.pop_back(); // remove '('
            i++;
        } else {
            char c = s[i];
            while (!op.empty() && op.back() != '(') {
                char top = op.back();
                if (prec(top) > prec(c)) {
                    out.push_back(string(1, top));
                    op.pop_back();
                } else if (prec(top) == prec(c) && c != '^') {
                    // left associative
                    out.push_back(string(1, top));
                    op.pop_back();
                } else break;
            }
            op.push_back(c);
            i++;
        }
    }
    while (!op.empty()) {
        out.push_back(string(1, op.back()));
        op.pop_back();
    }
    for (size_t j = 0; j < out.size(); j++)
        cout << out[j] << (j + 1 == out.size() ? "" : " ");
    cout << "\n";
    return 0;
}
