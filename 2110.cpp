#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Seg { int p, k; };
bool cmp(Seg a, Seg b) { return a.k < b.k; }

int main() {
    int B;
    if (!(cin >> B)) return 0;
    vector<Seg> v(B);
    for (int i = 0; i < B; i++) cin >> v[i].p >> v[i].k;
    sort(v.begin(), v.end(), cmp);
    vector<int> dp(B + 1, 0);
    for (int i = 1; i <= B; i++) {
        int st = v[i - 1].p;
        int len = v[i - 1].k - v[i - 1].p + 1;
        int lo = 0, hi = i - 1, res = 0;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (v[mid].k < st) { res = mid + 1; lo = mid + 1; }
            else hi = mid - 1;
        }
        dp[i] = max(dp[i - 1], dp[res] + len);
    }
    cout << dp[B] << '\n';
    return 0;
}
