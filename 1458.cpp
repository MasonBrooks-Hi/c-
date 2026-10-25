#include <iostream>
#include <cstdio>
using namespace std;

double H(int n, double x) {
    if (n == 0) return 1;
    if (n == 1) return 2 * x;
    return 2 * x * H(n - 1, x) - 2 * (n - 1) * H(n - 2, x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    double x;
    if (!(cin >> n >> x)) return 0;
    printf("%.2lf\n", H(n, x));
    return 0;
}
