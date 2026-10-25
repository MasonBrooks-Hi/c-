#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    if (!(cin >> s)) return 0;
    int bal = 0;
    for (char c : s) {
        if (c == '(') bal++;
        else if (c == ')') {
            bal--;
            if (bal < 0) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << (bal == 0 ? "YES" : "NO") << "\n";
    return 0;
}
