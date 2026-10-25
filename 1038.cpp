#include <iostream>
using namespace std;
int main() {
    long long N;
    if (!(cin >> N)) return 0;
    long long neg = 0;
    if (N < 0) { neg = 1; N = -N; }
    long long r = 0;
    while (N > 0) { r = r * 10 + N % 10; N /= 10; }
    if (neg) cout << "-";
    cout << r << "\n";
    return 0;
}
