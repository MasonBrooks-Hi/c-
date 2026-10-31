#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<long long> r;
vector<long long> d, st, en;

bool check(int mid) {
    vector<long long> diff(n + 2, 0);
    for (int i = 0; i < mid; i++) {
        diff[st[i]] += d[i];
        diff[en[i] + 1] -= d[i];
    }
    long long use = 0;
    for (int i = 1; i <= n; i++) {
        use += diff[i];
        if (use > r[i]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    if (!(cin >> n >> m)) return 0;
    r.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> r[i];
    d.resize(m); st.resize(m); en.resize(m);
    for (int i = 0; i < m; i++) cin >> d[i] >> st[i] >> en[i];
    if (check(m)) {
        cout << 0 << "\n";
        return 0;
    }
    int lo = 1, hi = m, ans = m + 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) lo = mid + 1;
        else { ans = mid; hi = mid - 1; }
    }
    cout << -1 << "\n" << ans << "\n";
    return 0;
}
