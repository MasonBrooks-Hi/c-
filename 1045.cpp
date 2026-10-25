#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    double x;
    int n;
    if (!(cin >> x >> n)) return 0;
    double s = 0, t = 1;
    for (int i = 0; i <= n; i++) { s += t; t *= x; }
    printf("%.2f\n", s);
    return 0;
}
