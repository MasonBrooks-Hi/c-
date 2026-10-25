#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    string out;
    size_t i = 0;
    while (i < s.size()) {
        size_t j = i;
        while (j < s.size() && s[j] != ' ') j++;
        string w = s.substr(i, j - i);
        reverse(w.begin(), w.end());
        if (i > 0) out += ' ';
        out += w;
        i = j + 1;
    }
    cout << out << "\n";
    return 0;
}
