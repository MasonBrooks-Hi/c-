#include <iostream>
using namespace std;

long long sumdiv(long long a) {
    long long s = 0;
    for (long long i = 1; i * i <= a; i++) {
        if (a % i == 0) {
            s += i;
            if (i != a / i) s += a / i;
        }
    }
    return s - a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (long long a = 2; ; a++) {
        long long b = sumdiv(a);
        if (b > a) {
            if (sumdiv(b) == a) {
                cout << a << " " << b << "\n";
                return 0;
            }
        }
    }
    return 0;
}
