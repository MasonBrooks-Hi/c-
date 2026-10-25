#include <iostream>
using namespace std;

long long phi(long long n) {
    long long r = n;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            r = r / i * (i - 1);
        }
    }
    if (n > 1) r = r / n * (n - 1);
    return r;
}

int main() {
    long long n;
    while (cin >> n && n != 0) {
        cout << phi(n) << "\n";
    }
    return 0;
}
