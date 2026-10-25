#include <iostream>
using namespace std;

int main() {
    int K;
    if (!(cin >> K)) return 0;
    while (K--) {
        long long A, B;
        cin >> A >> B;
        long long D = B - A;
        if (D == 0) {
            cout << 0 << "\n";
            continue;
        }
        long long n = 1;
        while (true) {
            long long maxd = (n + 1) * (n + 1) / 4;
            if (maxd >= D) {
                cout << n << "\n";
                break;
            }
            n++;
        }
    }
    return 0;
}
