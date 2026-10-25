#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    double a, b;
    cin >> a >> b;
    double k = (int)(a / b);
    double r = a - k * b;
    printf("%.4lf\n", r);
    return 0;
}
