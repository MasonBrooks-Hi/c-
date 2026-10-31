#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 99999997;

struct BIT {
    int n;
    vector<int> t;
    BIT(int n) : n(n), t(n + 1, 0) {}
    void add(int i, int v) { for (; i <= n; i += i & -i) t[i] += v; }
    int sum(int i) { int s = 0; for (; i > 0; i -= i & -i) s += t[i]; return s; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    if (!(cin >> n)) return 0;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) cin >> p[i].first;
    for (int i = 0; i < n; i++) cin >> p[i].second;
    sort(p.begin(), p.end());
    vector<int> b(n);
    for (int i = 0; i < n; i++) b[i] = p[i].second;
    // compress b
    vector<int> sb = b;
    sort(sb.begin(), sb.end());
    for (int i = 0; i < n; i++)
        b[i] = lower_bound(sb.begin(), sb.end(), b[i]) - sb.begin() + 1;
    BIT bit(n);
    long long inv = 0;
    for (int i = 0; i < n; i++) {
        inv = (inv + (i - bit.sum(b[i]))) % MOD;
        bit.add(b[i], 1);
    }
    cout << inv << "\n";
    return 0;
}
