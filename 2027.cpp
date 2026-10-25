#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    if (!(cin >> s)) return 0;
    cout << s << '\n';
    while (s.size() > 1) {
        unsigned long long prod = 1;
        for (char c : s)
            if (c != '0') prod *= (unsigned long long)(c - '0');
        s = to_string(prod);
        cout << s << '\n';
    }
    return 0;
}
