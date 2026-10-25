#include <iostream>
using namespace std;

long long mul(long long a, long long c, long long mod) {
    long long r = 0;
    a %= mod; c %= mod;
    while (c) {
        if (c & 1) r = (r + a) % mod;
        a = (a + a) % mod;
        c >>= 1;
    }
    return r;
}

long long powmod(long long base, long long e, long long mod) {
    long long r = 1 % mod;
    base %= mod;
    while (e) {
        if (e & 1) r = mul(r, base, mod);
        base = mul(base, base, mod);
        e >>= 1;
    }
    return r;
}

int main() {
    long long b, p, k;
    if (!(cin >> b >> p >> k)) return 0;
    long long r = powmod(b, p, k);
    cout << b << "^" << p << " mod " << k << "=" << r << "\n";
    return 0;
}
