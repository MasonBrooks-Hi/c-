#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Big {
    vector<int> d; // least significant digit first, base 10
    Big() { d.push_back(0); }
    Big(long long v) { if (v == 0) d.push_back(0); while (v) { d.push_back(v % 10); v /= 10; } }
};

Big mul(const Big& a, const Big& b) {
    Big r;
    r.d.assign(a.d.size() + b.d.size(), 0);
    for (size_t i = 0; i < a.d.size(); i++)
        for (size_t j = 0; j < b.d.size(); j++)
            r.d[i + j] += a.d[i] * b.d[j];
    int carry = 0;
    for (size_t i = 0; i < r.d.size(); i++) {
        int cur = r.d[i] + carry;
        r.d[i] = cur % 10;
        carry = cur / 10;
    }
    while (carry) { r.d.push_back(carry % 10); carry /= 10; }
    while (r.d.size() > 1 && r.d.back() == 0) r.d.pop_back();
    return r;
}

int cmp(const Big& a, const Big& b) {
    if (a.d.size() != b.d.size()) return a.d.size() < b.d.size() ? -1 : 1;
    for (int i = (int)a.d.size() - 1; i >= 0; i--)
        if (a.d[i] != b.d[i]) return a.d[i] < b.d[i] ? -1 : 1;
    return 0;
}

string tos(const Big& a) {
    string s;
    for (int i = (int)a.d.size() - 1; i >= 0; i--) s += char('0' + a.d[i]);
    return s;
}

Big getval(const string& s, int l, int r) {
    Big v; v.d.clear(); v.d.push_back(0);
    for (int i = l; i <= r; i++) {
        int dig = s[i] - '0';
        for (size_t k = 0; k < v.d.size(); k++) v.d[k] *= 10;
        int carry = 0;
        for (size_t k = 0; k < v.d.size(); k++) { int cur = v.d[k] + carry; v.d[k] = cur % 10; carry = cur / 10; }
        if (carry) v.d.push_back(carry);
        int carry2 = dig;
        for (size_t k = 0; k < v.d.size(); k++) { int cur = v.d[k] + carry2; v.d[k] = cur % 10; carry2 = cur / 10; }
        while (carry2) { v.d.push_back(carry2 % 10); carry2 /= 10; }
    }
    if (v.d.empty()) v.d.push_back(0);
    while (v.d.size() > 1 && v.d.back() == 0) v.d.pop_back();
    return v;
}

int main() {
    int N, K;
    if (!(cin >> N >> K)) return 0;
    string s;
    cin >> s;
    vector<vector<Big>> dp(N + 1, vector<Big>(K + 1, Big(0)));
    for (int i = 1; i <= N; i++) dp[i][0] = getval(s, 0, i - 1);
    for (int j = 1; j <= K; j++)
        for (int i = j + 1; i <= N; i++)
            for (int k = j; k < i; k++) {
                Big v = mul(dp[k][j - 1], getval(s, k, i - 1));
                if (cmp(v, dp[i][j]) > 0) dp[i][j] = v;
            }
    cout << tos(dp[N][K]) << '\n';
    return 0;
}
