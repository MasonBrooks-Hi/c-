#include <iostream>
using namespace std;
int gcd(int a, int b) {
    while (b) { int t = a % b; a = b; b = t; }
    return a;
}
int main() {
    int m, n;
    cin >> m >> n;
    int g = gcd(m, n);
    cout << m / g << " " << n / g << "\n";
    return 0;
}
