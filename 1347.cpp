#include <iostream>
using namespace std;

long long C(int n, int k) {
    if (k < 0 || k > n) return 0;
    long long res = 1;
    if (k > n - k) k = n - k;
    for (int i = 1; i <= k; i++) {
        res = res * (n - k + i) / i;
    }
    return res;
}

int main() {
    int m, n;
    if (cin >> m >> n)
        cout << C(m - 1 + n - 1, m - 1) << "\n";
    return 0;
}
