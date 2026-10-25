#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    for (char &c : s) if (c >= 'a' && c <= 'z') c = c - 'a' + 'A';
    cout << s << endl;
    return 0;
}
