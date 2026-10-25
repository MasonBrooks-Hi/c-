#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    double r;
    cin >> r;
    double v = 4.0 / 3.0 * 3.14 * r * r * r;
    printf("%.2lf\n", v);
    return 0;
}
