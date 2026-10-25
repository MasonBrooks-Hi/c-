#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    if (!(cin >> n)) return 0;
    for (long long N = 2; ; N++) {
        long long sum = N * (N + 1) / 2;
        long long my = (sum - n);
        if (my % 3 != 0) continue;
        my /= 3;
        if (my > 1 && my <= N) {
            cout << my << " " << N << "\n";
            return 0;
        }
    }
    return 0;
}
