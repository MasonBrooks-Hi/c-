#include <iostream>
#include <string>
using namespace std;

const int MOD = 10007;

struct P {
    long long z, o;
};

string s;
int pos;

P leaf() { return {1, 1}; }

P And(P a, P b) {
    P r;
    r.o = a.o * b.o % MOD;
    long long total = (a.z + a.o) * (b.z + b.o) % MOD;
    r.z = (total - r.o) % MOD;
    if (r.z < 0) r.z += MOD;
    return r;
}

P Or(P a, P b) {
    P r;
    r.z = a.z * b.z % MOD;
    long long total = (a.z + a.o) * (b.z + b.o) % MOD;
    r.o = (total - r.z) % MOD;
    if (r.o < 0) r.o += MOD;
    return r;
}

P parseXor();
P parseAnd();

P parseFactor() {
    if (pos < (int)s.size() && s[pos] == '(') {
        pos++;
        P r = parseXor();
        pos++; // consume ')'
        return r;
    }
    return leaf();
}

P parseAnd() {
    P res = parseFactor();
    while (pos < (int)s.size() && s[pos] == '*') {
        pos++;
        P r = parseFactor();
        res = And(res, r);
    }
    return res;
}

P parseXor() {
    P res = parseAnd();
    while (pos < (int)s.size() && s[pos] == '+') {
        pos++;
        P r = parseAnd();
        res = Or(res, r);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int L;
    if (!(cin >> L)) return 0;
    cin >> s;
    pos = 0;
    P ans = parseXor();
    cout << ans.z % MOD << "\n";
    return 0;
}
