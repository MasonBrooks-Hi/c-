#include <iostream>
#include <string>
using namespace std;

int main() {
    long long n;
    if (!(cin >> n)) return 0;
    if (n == 0) {
        cout << 0 << "\n";
        return 0;
    }
    string s;
    while (n > 0) {
        s = char('0' + (n % 8)) + s;
        n /= 8;
    }
    cout << s << "\n";
    return 0;
}
