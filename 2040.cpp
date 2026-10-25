#include <iostream>
#include <vector>
using namespace std;

// 大整数：十进制小端序
using Big = vector<int>;

Big addBig(const Big &a, const Big &b) {
    Big c;
    int carry = 0;
    for (size_t i = 0; i < max(a.size(), b.size()) || carry; i++) {
        int s = carry;
        if (i < a.size()) s += a[i];
        if (i < b.size()) s += b[i];
        c.push_back(s % 10);
        carry = s / 10;
    }
    return c;
}

Big mulSmall(const Big &a, int m) {
    Big c;
    int carry = 0;
    for (size_t i = 0; i < a.size() || carry; i++) {
        long long cur = carry;
        if (i < a.size()) cur += (long long)a[i] * m;
        c.push_back((int)(cur % 10));
        carry = (int)(cur / 10);
    }
    return c;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    Big fact = {1};
    Big sum = {0};
    for (int i = 1; i <= n; i++) {
        fact = mulSmall(fact, i);
        sum = addBig(sum, fact);
    }
    for (auto it = sum.rbegin(); it != sum.rend(); ++it) cout << *it;
    cout << '\n';
    return 0;
}
