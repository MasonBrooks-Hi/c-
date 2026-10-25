#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    double x;
    int n;
    if (!(cin >> x >> n)) return 0;
    for (int i = 0; i < n; i++) x *= 1.001;
    printf("%.4f\n", x);
    return 0;
}
