#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    string out;
    bool first = true;
    size_t i = 0;
    while (i < s.size()) {
        while (i < s.size() && s[i] == ' ') i++;
        if (i >= s.size()) break;
        int len = 0;
        while (i < s.size() && s[i] != ' ') len++, i++;
        if (!first) out += ',';
        first = false;
        out += to_string(len);
    }
    cout << out << "\n";
    return 0;
}
