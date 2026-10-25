#include <iostream>
#include <string>
using namespace std;
int main() {
    int r;
    long long n;
    cin >> r >> n;
    if (n == 0) { cout << "0\n"; return 0; }
    string s;
    long long x = n;
    while (x > 0) {
        int d = x % r;
        char c = (d < 10) ? (char)('0' + d) : (char)('A' + d - 10);
        s = c + s;
        x /= r;
    }
    cout << s << "\n";
    return 0;
}
