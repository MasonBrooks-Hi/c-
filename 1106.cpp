#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);
    for (char &c : a) c = tolower((unsigned char)c);
    for (char &c : b) c = tolower((unsigned char)c);
    if (a < b) cout << "<\n";
    else if (a > b) cout << ">\n";
    else cout << "=\n";
    return 0;
}
