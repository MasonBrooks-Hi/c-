#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long N;
    if (!(cin >> N)) return 0;
    vector<long long> factors;
    long long n = N;
    for (long long p = 2; p * p <= n; p++) {
        while (n % p == 0) { factors.push_back(p); n /= p; }
    }
    if (n > 1) factors.push_back(n);
    for (size_t i = 0; i < factors.size(); i++) {
        if (i) cout << "*";
        cout << factors[i];
    }
    cout << "\n";
    return 0;
}
