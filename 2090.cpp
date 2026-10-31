#include <iostream>
using namespace std;

const int N = 1000005;
long long c[N];

int main() {
    int n;
    if (!(cin >> n)) return 0;
    for (int i = 1; i <= n; i++) cin >> c[i];
    int m, p1, s1, s2;
    cin >> m >> p1 >> s1 >> s2;
    c[p1] += s1;
    long long L = 0, R = 0;
    for (int i = 1; i <= n; i++) {
        if (i < m) L += c[i] * (m - i);
        else if (i > m) R += c[i] * (i - m);
    }
    long long best = 1e18;
    int ans = 1;
    for (int p2 = 1; p2 <= n; p2++) {
        long long L2 = L, R2 = R;
        if (p2 < m) L2 += (long long)s2 * (m - p2);
        else if (p2 > m) R2 += (long long)s2 * (p2 - m);
        long long diff = (L2 > R2) ? (L2 - R2) : (R2 - L2);
        if (diff < best) { best = diff; ans = p2; }
    }
    cout << ans << '\n';
    return 0;
}
