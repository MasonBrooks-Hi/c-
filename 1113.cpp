#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    string out;
    bool space = false;
    for (char c : s) {
        if (c == ' ') {
            if (space) continue;
            space = true;
            out += c;
        } else {
            space = false;
            out += c;
        }
    }
    cout << out << "\n";
    return 0;
}
