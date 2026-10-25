#include <iostream>
#include <string>
using namespace std;
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    string t1 = s1 + s1, t2 = s2 + s2;
    bool ok = false;
    if (t2.find(s1) != string::npos) ok = true;
    if (t1.find(s2) != string::npos) ok = true;
    cout << (ok ? "true" : "false") << "\n";
    return 0;
}
