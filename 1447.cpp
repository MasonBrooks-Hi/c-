#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k;
    if (!(cin >> k)) return 0;
    string s;
    cin >> s;
    int n = (int)s.size();
    int cnt = 1;
    char best = 0;
    bool found = false;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            cnt++;
            if (cnt >= k) { best = s[i]; found = true; }
        } else {
            cnt = 1;
        }
    }
    if (found) cout << best << "\n";
    else cout << "No\n";
    return 0;
}
