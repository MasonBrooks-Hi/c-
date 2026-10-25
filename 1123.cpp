#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    string s;
    cin >> s;
    string r = s;
    reverse(r.begin(), r.end());
    if (s == r) cout << "yes\n";
    else cout << "no\n";
    return 0;
}
