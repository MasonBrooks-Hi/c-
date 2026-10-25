#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    cin >> s;
    string out;
    int i = 0;
    while (i < (int)s.size()) {
        int j = i;
        while (j < (int)s.size() && s[j] == s[i]) j++;
        out += to_string(j - i);
        out += s[i];
        i = j;
    }
    cout << out << "\n";
    return 0;
}
