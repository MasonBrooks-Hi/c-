#include <iostream>
#include <string>
using namespace std;
int main() {
    string s, t;
    cin >> s >> t;
    int n = (int)s.size(), m = (int)t.size();
    string A = s + s, B = t + t;
    int cap = (n < m) ? n : m;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int len = 0;
            while (len < cap && A[i + len] == B[j + len]) len++;
            if (len > ans) ans = len;
        }
    }
    cout << ans << "\n";
    return 0;
}
