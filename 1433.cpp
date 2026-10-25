#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cnt;
    if (!(cin >> cnt)) return 0;
    int x, ans = 0;
    for (int i = 0; i < cnt; i++) {
        cin >> x;
        ans ^= x;
    }
    cout << ans << "\n";
    return 0;
}
