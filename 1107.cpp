#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);
    string A, B;
    for (char c : a) if (!isspace((unsigned char)c)) A += tolower((unsigned char)c);
    for (char c : b) if (!isspace((unsigned char)c)) B += tolower((unsigned char)c);
    if (A == B) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
