#include <iostream>
#include <string>
using namespace std;
int main() {
    string s, a, b;
    getline(cin, s);
    getline(cin, a);
    getline(cin, b);
    string out;
    size_t i = 0;
    bool first = true;
    while (i < s.size()) {
        while (i < s.size() && s[i] == ' ') i++;
        if (i >= s.size()) break;
        string word;
        while (i < s.size() && s[i] != ' ') word += s[i++];
        if (!first) out += ' ';
        first = false;
        if (word == a) out += b;
        else out += word;
    }
    cout << out << "\n";
    return 0;
}
