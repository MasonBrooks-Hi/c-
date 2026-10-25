#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int m;
    cin >> m;
    while (m--) {
        long long x;
        cin >> x;
        auto it = lower_bound(a.begin(), a.end(), x);
        long long best;
        if (it == a.end()) best = a[n - 1];
        else if (it == a.begin()) best = *it;
        else {
            long long v1 = *it, v2 = *(it - 1);
            long long d1 = v1 - x, d2 = x - v2;
            best = (d2 <= d1) ? v2 : v1;
        }
        cout << best << "\n";
    }
    return 0;
}
