#include <iostream>
#include <string>
#include <vector>
using namespace std;

int cmp(const string& a, const string& b) {
    string x = a, y = b;
    size_t i = 0;
    while (i < x.size() && x[i] == '0') ++i;
    size_t j = 0;
    while (j < y.size() && y[j] == '0') ++j;
    x = x.substr(i);
    y = y.substr(j);
    if (x.size() != y.size()) return x.size() < y.size() ? -1 : 1;
    for (size_t k = 0; k < x.size(); ++k) {
        if (x[k] != y[k]) return x[k] < y[k] ? -1 : 1;
    }
    return 0;
}

string mulDigit(const string& a, int d) {
    if (d == 0) return "0";
    string out;
    int carry = 0;
    for (int i = (int)a.size() - 1; i >= 0; --i) {
        int v = (a[i] - '0') * d + carry;
        out.push_back((char)('0' + v % 10));
        carry = v / 10;
    }
    if (carry) out.push_back((char)('0' + carry));
    reverse(out.begin(), out.end());
    return out;
}

string sub(const string& a, const string& b) {
    string x = a, y = b;
    vector<int> A, B;
    for (char c : x) A.push_back(c - '0');
    for (char c : y) B.push_back(c - '0');
    vector<int> res(A.size(), 0);
    int borrow = 0;
    for (int i = (int)A.size() - 1; i >= 0; --i) {
        int bi = (int)B.size() - (A.size() - i);
        int bv = bi >= 0 ? B[bi] : 0;
        int v = A[i] - bv - borrow;
        if (v < 0) { v += 10; borrow = 1; } else borrow = 0;
        res[i] = v;
    }
    string out;
    size_t k = 0;
    while (k < res.size() - 1 && res[k] == 0) ++k;
    for (; k < res.size(); ++k) out.push_back(res[k] + '0');
    return out;
}

int main() {
    string a, b;
    if (!(cin >> a >> b)) return 0;
    string rem = "0";
    string quo;
    for (char ch : a) {
        if (rem == "0") rem = string(1, ch);
        else rem.push_back(ch);
        int q = 0;
        for (int d = 9; d >= 0; --d) {
            if (cmp(mulDigit(b, d), rem) <= 0) { q = d; break; }
        }
        if (!(quo.empty() && q == 0)) quo.push_back((char)('0' + q));
        string prod = mulDigit(b, q);
        rem = sub(rem, prod);
    }
    if (quo.empty()) quo = "0";
    cout << quo << "\n" << rem << endl;
    return 0;
}
