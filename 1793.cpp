// 1793 麦森数
// Output number of digits of 2^P - 1 and its last 500 decimal digits (10 lines x 50).
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int P;
    if (scanf("%d", &P) != 1) return 0;
    long double lg = (long double)P * log10l(2.0L);
    long long D = (long long)floorl(lg) + 1;
    printf("%lld\n", D);

    const int LIMBS = 125; // 125 * 4 = 500 digits, base 10000
    auto mul = [&](const vector<int> &x, const vector<int> &y) {
        vector<long long> tmp(LIMBS, 0);
        for (int i = 0; i < LIMBS; i++) {
            if (!x[i]) continue;
            for (int j = 0; j < LIMBS - i; j++) {
                if (!y[j]) continue;
                tmp[i + j] += (long long)x[i] * y[j];
            }
        }
        vector<int> res(LIMBS, 0);
        long long carry = 0;
        for (int i = 0; i < LIMBS; i++) {
            long long cur = tmp[i] + carry;
            res[i] = (int)(cur % 10000);
            carry = cur / 10000;
        }
        return res;
    };
    vector<int> base(LIMBS, 0), res(LIMBS, 0);
    base[0] = 2;
    res[0] = 1;
    long long e = P;
    while (e > 0) {
        if (e & 1) res = mul(res, base);
        e >>= 1;
        if (e) base = mul(base, base);
    }
    // 2^P - 1 (mod 10^500): 2^P mod 10^500 >= 1 always (no factor 5), so no borrow chain
    res[0] -= 1;
    // print 500 digits, 50 per line (all limbs zero-padded to 4 digits)
    string digits;
    char buf[8];
    for (int i = LIMBS - 1; i >= 0; i--) {
        snprintf(buf, sizeof(buf), "%04d", res[i]);
        digits += buf;
    }
    for (int line = 0; line < 10; line++) {
        printf("%.50s\n", digits.c_str() + line * 50);
    }
    return 0;
}
