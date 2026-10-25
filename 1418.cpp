#include <iostream>
#include <string>
#include <vector>
using namespace std;

int digitSum(unsigned long long x, int n) {
    int s = 0;
    // x represented with exactly n digits (leading zeros contribute 0)
    for (int i = 0; i < n; i++) {
        s += (int)(x % 10);
        x /= 10;
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    if (!(cin >> n)) return 0;
    unsigned long long S;
    cin >> S;
    unsigned long long pow10 = 1;
    for (int i = 0; i < n; i++) pow10 *= 10; // 10^n
    unsigned long long R = (pow10 - 1) / 9;   // repunit
    unsigned long long fact = 1;
    for (int i = 1; i <= n - 1; i++) fact *= i; // (n-1)!
    unsigned long long cand = 0;
    bool found = false;
    for (int dsum = 0; dsum <= 9 * n; dsum++) {
        __int128 T = (__int128)fact * R * dsum;
        if (T < S) continue;
        unsigned long long X = (unsigned long long)(T - S);
        if (X >= pow10) continue;
        if (digitSum(X, n) == dsum) {
            cand = X;
            found = true;
            break;
        }
    }
    string out = to_string(cand);
    while ((int)out.size() < n) out = "0" + out;
    cout << out << "\n";
    return 0;
}
