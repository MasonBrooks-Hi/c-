#include <iostream>
using namespace std;

const int MOD = 10007;

long long power(long long a, long long b) {
    long long r = 1 % MOD;
    a %= MOD;
    while (b) {
        if (b & 1) r = r * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, k, n, m;
    if (!(cin >> a >> b >> k >> n >> m)) return 0;
    long long c = 1;
    int nn = n, kk = k;
    // C(k, n)
    if (n > k - n) n = k - n;
    int num = k, den = n;
    for (int i = 1; i <= n; i++) {
        c = c * num % MOD;
        num--;
    }
    long long denom = 1;
    for (int i = 2; i <= n; i++) denom = denom * i % MOD;
    c = c * power(denom, MOD - 2) % MOD;
    c = c * power(a % MOD, nn) % MOD;
    c = c * power(b % MOD, m) % MOD;
    cout << c << "\n";
    return 0;
}
