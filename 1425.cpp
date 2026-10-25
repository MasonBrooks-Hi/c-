#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    if (!(cin >> n)) return 0;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    long long ans = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] <= a[i - 1]) {
            long long need = a[i - 1] + 1;
            ans += need - a[i];
            a[i] = need;
        }
    }
    cout << ans << "\n";
    return 0;
}
