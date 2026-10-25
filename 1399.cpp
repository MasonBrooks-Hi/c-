#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string addBig(const string &a, const string &b) {
    string res;
    int i = (int)a.size() - 1, j = (int)b.size() - 1, carry = 0;
    while (i >= 0 || j >= 0 || carry) {
        int x = (i >= 0) ? a[i--] - '0' : 0;
        int y = (j >= 0) ? b[j--] - '0' : 0;
        int s = x + y + carry;
        res.push_back((s % 10) + '0');
        carry = s / 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    string a, b;
    if (!(cin >> a >> b)) return 0;
    cout << addBig(a, b) << "\n";
    return 0;
}
