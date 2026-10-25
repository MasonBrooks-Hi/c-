#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    double r;
    cin >> r;
    double pi = 3.14159;
    printf("%.4lf %.4lf %.4lf\n", 2 * r, 2 * pi * r, pi * r * r);
    return 0;
}
