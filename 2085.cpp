#include <iostream>
#include <algorithm>
using namespace std;

int a[30005];

int main() {
    int w;
    if (!(cin >> w)) return 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int l = 0, r = n - 1, ans = 0;
    while (l <= r) {
        if (a[l] + a[r] <= w) l++;
        r--;
        ans++;
    }
    cout << ans << '\n';
    return 0;
}
