#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Seg { int p, k; };
bool cmp(Seg a, Seg b) { return a.k < b.k; }

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<Seg> v(n);
    for (int i = 0; i < n; i++) cin >> v[i].p >> v[i].k;
    sort(v.begin(), v.end(), cmp);
    vector<long long> dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int st = v[i - 1].p;
        int len = v[i - 1].k - v[i - 1].p;
        int lo = 0, hi = i - 1, res = 0;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (v[mid].k <= st) { res = mid + 1; lo = mid + 1; }
            else hi = mid - 1;
        }
        dp[i] = max(dp[i - 1], dp[res] + len);
    }
    cout << dp[n] << '\n';
    return 0;
}
