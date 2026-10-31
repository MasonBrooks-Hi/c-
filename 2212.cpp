#include <iostream>
using namespace std;

long long exgcd(long long a, long long b, long long& x, long long& y) {
    if (b == 0) { x = 1; y = 0; return a; }
    long long x1, y1;
    long long g = exgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long a, b;
    if (!(cin >> a >> b)) return 0;
    long long x, y;
    exgcd(a, b, x, y);
    x %= b;
    if (x <= 0) x += b;
    cout << x << "\n";
    return 0;
}
