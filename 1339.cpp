#include <iostream>
using namespace std;
int main() {
    int N;
    if (cin >> N) {
        long long dp0 = 8, dp1 = 1; // even=8, odd=1 for 1-digit
        for (int i = 2; i <= N; ++i) {
            long long n0 = (dp0 * 9 + dp1 * 1) % 12345;
            long long n1 = (dp1 * 9 + dp0 * 1) % 12345;
            dp0 = n0; dp1 = n1;
        }
        cout << dp0 << endl;
    }
    return 0;
}
