#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

double max2(double a, double b, double c) {
    return max(a, max(b, c));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    double a, b, c;
    if (!(cin >> a >> b >> c)) return 0;
    double m = max2(a, b, c) / (max2(a + b, b, c) * max2(a, b, b + c));
    printf("%.3lf\n", m);
    return 0;
}
