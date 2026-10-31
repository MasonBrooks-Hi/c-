#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;

const long long BASE = 1000000000;

struct Big {
    vector<long long> d; // little-endian, base 1e9
    Big() { d.push_back(0); }
    Big(long long v) { d.push_back(v); }
};

Big mul(const Big& a, long long k) {
    Big r;
    r.d.clear();
    long long carry = 0;
    for (size_t i = 0; i < a.d.size(); i++) {
        long long cur = a.d[i] * k + carry;
        r.d.push_back(cur % BASE);
        carry = cur / BASE;
    }
    while (carry) { r.d.push_back(carry % BASE); carry /= BASE; }
    return r;
}

Big div(const Big& a, long long k) {
    Big r;
    vector<long long> tmp;
    long long rem = 0;
    for (int i = (int)a.d.size() - 1; i >= 0; i--) {
        rem = rem * BASE + a.d[i];
        tmp.push_back(rem / k);
        rem %= k;
    }
    while (tmp.size() > 1 && tmp.back() == 0) tmp.pop_back();
    reverse(tmp.begin(), tmp.end());
    r.d = tmp;
    return r;
}

bool lessBig(const Big& a, const Big& b) {
    if (a.d.size() != b.d.size()) return a.d.size() < b.d.size();
    for (int i = (int)a.d.size() - 1; i >= 0; i--)
        if (a.d[i] != b.d[i]) return a.d[i] < b.d[i];
    return false;
}

string tostr(const Big& a) {
    string s = to_string(a.d.back());
    char buf[16];
    for (int i = (int)a.d.size() - 2; i >= 0; i--) {
        snprintf(buf, sizeof(buf), "%09lld", a.d[i]);
        s += buf;
    }
    return s;
}

struct Min {
    long long a, b;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    if (!(cin >> n)) return 0;
    long long ka, kb;
    cin >> ka >> kb;
    vector<Min> m(n);
    for (int i = 0; i < n; i++) cin >> m[i].a >> m[i].b;
    sort(m.begin(), m.end(), [](const Min& x, const Min& y) {
        return x.a * x.b < y.a * y.b;
    });
    Big product(ka);
    Big mx;
    for (int i = 0; i < n; i++) {
        Big q = div(product, m[i].b);
        if (lessBig(mx, q)) mx = q;
        product = mul(product, m[i].a);
    }
    cout << tostr(mx) << "\n";
    return 0;
}
