#include <iostream>
using namespace std;

const int MOD = 1000000007;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    if (n == 1) { cout << 1 << '\n'; return 0; }
    if (n == 2) { cout << 2 << '\n'; return 0; }
    long long a = 1, b = 2, c;
    for (int i = 3; i <= n; i++) {
        c = (a + b) % MOD;
        a = b;
        b = c;
    }
    cout << b << '\n';
    return 0;
}
