#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    if (!(cin >> n)) return 0;
    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    int ans = 0;
    int prev = 0;
    for (int i = 0; i < n; i++) {
        if (h[i] > prev) ans += h[i] - prev;
        prev = h[i];
    }
    cout << ans << "\n";
    return 0;
}
