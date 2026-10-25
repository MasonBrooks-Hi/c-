#include <iostream>
#include <cstdio>
using namespace std;

double f(double x, int n) {
    if (n == 0) return x;
    return x / (n + f(x, n - 1));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    double x;
    int n;
    if (!(cin >> x >> n)) return 0;
    printf("%.2lf\n", f(x, n));
    return 0;
}
