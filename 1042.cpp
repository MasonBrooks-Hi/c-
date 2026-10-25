#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    int n;
    if (!(cin >> n)) return 0;
    double s = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) s += 1.0 / i;
        else s -= 1.0 / i;
    }
    printf("%.4f\n", s);
    return 0;
}
