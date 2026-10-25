#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    for (char& c : s) {
        if (c >= 'A' && c <= 'Z') {
            c = (char)((c - 'A' - 5 + 26) % 26 + 'A');
        }
    }
    cout << s << endl;
    return 0;
}
