#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    vector<string> words;
    size_t i = 0;
    while (i < s.size()) {
        while (i < s.size() && s[i] == ' ') i++;
        if (i >= s.size()) break;
        string w;
        while (i < s.size() && s[i] != ' ') w += s[i++];
        words.push_back(w);
    }
    string out;
    for (int k = (int)words.size() - 1; k >= 0; k--) {
        if (k < (int)words.size() - 1) out += ' ';
        out += words[k];
    }
    cout << out << "\n";
    return 0;
}
