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
    if (n == 0) { cout << 0 << "\n"; return 0; }
    int f1 = 1, f2 = 1;
    for (int i = 1; i < n; i++) {
        if (h[i] > h[i - 1]) f1 = f2 + 1;
        else if (h[i] < h[i - 1]) f2 = f1 + 1;
    }
    int ans = (f1 > f2) ? f1 : f2;
    cout << ans << "\n";
    return 0;
}
