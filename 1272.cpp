#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int val(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    return c - 'A' + 10;
}
char chr(int v) {
    if (v < 10) return (char)('0' + v);
    return (char)('A' + v - 10);
}

bool isPal(const vector<int>& v) {
    int n = (int)v.size();
    for (int i = 0; i < n; ++i) if (v[i] != v[n - 1 - i]) return false;
    return true;
}

vector<int> add(const vector<int>& a, const vector<int>& b, int base) {
    vector<int> res;
    int carry = 0;
    int n = max(a.size(), b.size());
    for (int i = 0; i < n || carry; ++i) {
        int x = i < (int)a.size() ? a[i] : 0;
        int y = i < (int)b.size() ? b[i] : 0;
        int s = x + y + carry;
        res.push_back(s % base);
        carry = s / base;
    }
    return res;
}

int main() {
    int base;
    string m;
    if (!(cin >> base >> m)) return 0;
    vector<int> v;
    for (char c : m) v.push_back(val(c));
    reverse(v.begin(), v.end()); // lsb first
    if (isPal(v)) { cout << "STEP=0" << endl; return 0; }
    for (int step = 1; step <= 30; ++step) {
        vector<int> rev = v;
        reverse(rev.begin(), rev.end());
        v = add(v, rev, base);
        if (isPal(v)) {
            cout << "STEP=" << step << endl;
            return 0;
        }
    }
    cout << "Impossible!" << endl;
    return 0;
}
