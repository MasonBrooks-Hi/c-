#include <iostream>
using namespace std;

long long power(long long a, long long b, long long mod) {
    long long r = 1 % mod;
    a %= mod;
    while (b) {
        if (b & 1) r = r * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, m, k, x;
    if (!(cin >> n >> m >> k >> x)) return 0;
    long long pw = power(10, k, n);
    long long shift = (pw * (m % n)) % n;
    long long ans = (x % n + shift) % n;
    if (ans < 0) ans += n;
    cout << ans << "\n";
    return 0;
}
