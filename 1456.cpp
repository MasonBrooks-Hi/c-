#include <iostream>
using namespace std;

int akm(int m, int n) {
    if (m == 0) return n + 1;
    if (n == 0) return akm(m - 1, 1);
    return akm(m - 1, akm(m, n - 1));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m, n;
    if (!(cin >> m >> n)) return 0;
    cout << akm(m, n) << "\n";
    return 0;
}
