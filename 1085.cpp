#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string add(const string& a, const string& b) {
    string r;
    int i = (int)a.size() - 1, j = (int)b.size() - 1, carry = 0;
    while (i >= 0 || j >= 0 || carry) {
        int x = (i >= 0) ? a[i--] - '0' : 0;
        int y = (j >= 0) ? b[j--] - '0' : 0;
        int s = x + y + carry;
        r.push_back((s % 10) + '0');
        carry = s / 10;
    }
    reverse(r.begin(), r.end());
    return r;
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << add(a, b) << endl;
    return 0;
}
