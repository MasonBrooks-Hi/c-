#include <iostream>
using namespace std;

int main() {
    long long n;
    if (!(cin >> n)) return 0;
    for (long long p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            int cnt = 0;
            while (n % p == 0) {
                n /= p;
                cnt++;
            }
            cout << p << ' ' << cnt << '\n';
        }
    }
    if (n > 1) cout << n << ' ' << 1 << '\n';
    return 0;
}
