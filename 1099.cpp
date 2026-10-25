#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    for (char& c : s) {
        if (c >= 'a' && c <= 'y') c++;
        else if (c == 'z') c = 'a';
        else if (c >= 'A' && c <= 'Y') c++;
        else if (c == 'Z') c = 'A';
    }
    cout << s << endl;
    return 0;
}
