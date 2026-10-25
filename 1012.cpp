#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    int n;
    if (!(cin >> n)) return 0;
    double s = 0, x;
    for (int i = 0; i < n; i++) { cin >> x; s += x; }
    printf("%.4f\n", s / n);
    return 0;
}
