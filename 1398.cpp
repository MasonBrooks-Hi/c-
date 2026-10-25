#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, v;
    if (!(cin >> n >> m >> v)) return 0;
    vector<int> a(m), b(m), t(m);
    vector<int> rev(m, 0); // revenue per team = t*(b-a)
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i] >> t[i];
        rev[i] = t[i] * (b[i] - a[i]);
    }
    long long best = 0;
    int total = 1 << m;
    for (int mask = 0; mask < total; mask++) {
        long long revenue = 0;
        vector<int> load(n - 1, 0); // load per segment
        bool ok = true;
        for (int i = 0; i < m; i++) {
            if (mask & (1 << i)) {
                revenue += rev[i];
                for (int seg = a[i]; seg < b[i]; seg++) {
                    load[seg - 1] += t[i];
                    if (load[seg - 1] > v) { ok = false; break; }
                }
                if (!ok) break;
            }
        }
        if (ok && revenue > best) best = revenue;
    }
    cout << best << "\n";
    return 0;
}
