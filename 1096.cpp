#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string s;
    cin >> s;
    if (s.empty()) { cout << "no\n"; return 0; }
    if (isdigit((unsigned char)s[0])) { cout << "no\n"; return 0; }
    for (char c : s) {
        if (!(isalpha((unsigned char)c) || c == '_' || isdigit((unsigned char)c))) {
            cout << "no\n";
            return 0;
        }
    }
    cout << "yes\n";
    return 0;
}
