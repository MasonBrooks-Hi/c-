#include <iostream>
using namespace std;

long long C(int n, int m) {
    if (m < 0 || m > n) return 0;
    if (m == 0 || m == n) return 1;
    if (m > n - m) m = n - m;
    long long r = 1;
    for (int i = 1; i <= m; i++) {
        r = r * (n - m + i) / i;
    }
    return r;
}

int main() {
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int N, M;
        cin >> N >> M;
        cout << C(N, M) << "\n";
    }
    return 0;
}
