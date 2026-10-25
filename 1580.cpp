#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
    while (b) { long long t = a % b; a = b; b = t; }
    return a;
}

int main() {
    long long n, m;
    if (!(cin >> n >> m)) return 0;
    cout << "gcd=" << gcd(n, m) << "\n";
    return 0;
}
