#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    int n;
    if (!(cin >> n)) return 0;
    double e = 1, f = 1;
    for (int i = 1; i <= n; i++) { f *= i; e += 1.0 / f; }
    printf("%.10f\n", e);
    return 0;
}
