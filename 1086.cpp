#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string sub(const string& a, const string& b) {
    string r;
    int i = (int)a.size() - 1, j = (int)b.size() - 1, borrow = 0;
    while (i >= 0) {
        int x = a[i--] - '0' - borrow;
        int y = (j >= 0) ? b[j--] - '0' : 0;
        if (x < y) { x += 10; borrow = 1; } else borrow = 0;
        r.push_back((x - y) + '0');
    }
    reverse(r.begin(), r.end());
    size_t pos = r.find_first_not_of('0');
    if (pos == string::npos) return "0";
    return r.substr(pos);
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << sub(a, b) << endl;
    return 0;
}
