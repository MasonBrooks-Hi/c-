#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
    string s;
    cin >> s;
    // reverse step 3: flip case
    for (char& c : s) {
        if (islower((unsigned char)c)) c = (char)toupper((unsigned char)c);
        else if (isupper((unsigned char)c)) c = (char)tolower((unsigned char)c);
    }
    // reverse step 2: reverse string
    reverse(s.begin(), s.end());
    // reverse step 1: shift right by 3
    for (char& c : s) {
        if (c >= 'A' && c <= 'Z') c = (char)((c - 'A' + 3) % 26 + 'A');
        else if (c >= 'a' && c <= 'z') c = (char)((c - 'a' + 3) % 26 + 'a');
    }
    cout << s << endl;
    return 0;
}
