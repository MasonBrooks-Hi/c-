#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int run(const string& t, bool left) {
    int n = (int)t.size();
    int cnt = 0;
    char target = 0;
    if (left) {
        for (int i = 0; i < n; i++) {
            char c = t[i];
            if (c == 'w') cnt++;
            else if (target == 0) { target = c; cnt++; }
            else if (c == target) cnt++;
            else break;
        }
    } else {
        for (int i = n - 1; i >= 0; i--) {
            char c = t[i];
            if (c == 'w') cnt++;
            else if (target == 0) { target = c; cnt++; }
            else if (c == target) cnt++;
            else break;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    if (!(cin >> n)) return 0;
    string s;
    cin >> s;
    int ans = 0;
    for (int start = 0; start < n; start++) {
        string t = s.substr(start) + s.substr(0, start);
        int L = run(t, true);
        int R = run(t, false);
        int tot = L + R;
        if (tot > n) tot = n;
        if (tot > ans) ans = tot;
    }
    cout << ans << "\n";
    return 0;
}
