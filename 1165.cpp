#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    double x, a, b, c, d;
    cin >> x >> a >> b >> c >> d;
    double r = a * x * x * x + b * x * x + c * x + d;
    printf("%.7lf\n", r);
    return 0;
}
