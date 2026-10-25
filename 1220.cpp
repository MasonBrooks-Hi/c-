#include <iostream>
using namespace std;

long long comb(int a, int b) {
    if (b < 0 || b > a) return 0;
    if (b > a - b) b = a - b;
    long long r = 1;
    for (int i = 1; i <= b; i++) {
        r = r * (a - b + i) / i;
    }
    return r;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    long long catalan = comb(2 * n, n) / (n + 1);
    cout << catalan << "\n";
    return 0;
}
