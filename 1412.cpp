#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, t;
    if (!(cin >> n >> t)) return 0;
    vector<long long> x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) cin >> y[i];
    vector<pair<long long, long long>> ponds(n);
    for (int i = 0; i < n; i++) ponds[i] = {y[i], x[i]};
    sort(ponds.begin(), ponds.end());
    long long total = 0;
    for (auto& p : ponds) {
        long long yi = p.first, xi = p.second;
        if (t <= 0) break;
        long long can = min(xi, t / yi);
        total += can;
        t -= can * yi;
    }
    cout << total << "\n";
    return 0;
}
