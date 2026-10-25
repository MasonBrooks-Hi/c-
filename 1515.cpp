#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<long long> a(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) { cin >> a[i]; sum += a[i]; }
    long long avg = sum / n;
    int ans = 0;
    long long cur = 0;
    for (int i = 0; i < n; i++) {
        cur += a[i] - avg;
        if (i < n - 1 && cur != 0) ans++;
    }
    cout << ans << "\n";
    return 0;
}
