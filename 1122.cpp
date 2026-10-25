#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main() {
    string s;
    cin >> s;
    for (char &c : s) c = toupper((unsigned char)c);
    string out;
    int i = 0;
    while (i < (int)s.size()) {
        int j = i;
        while (j < (int)s.size() && s[j] == s[i]) j++;
        out += '(';
        out += s[i];
        out += ',';
        out += to_string(j - i);
        out += ')';
        i = j;
    }
    cout << out << "\n";
    return 0;
}
