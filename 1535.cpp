#include <iostream>
#include <string>
using namespace std;

long long powmod(long long base, long long e, long long mod) {
    long long r = 1 % mod;
    base %= mod;
    while (e) {
        if (e & 1) r = (r * base) % mod;
        base = (base * base) % mod;
        e >>= 1;
    }
    return r;
}

int main() {
    int k;
    if (!(cin >> k)) return 0;
    while (k--) {
        string s;
        cin >> s;
        long long n = 0;
        for (char c : s) n = n * 10 + (c - '0');
        cout << powmod(2011, n, 10000) << "\n";
    }
    return 0;
}
