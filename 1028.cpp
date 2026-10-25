#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int main() {
    int n;
    if (!(cin >> n)) return 0;
    double total = 0;
    for (int i = 0; i < n; i++) {
        double x, y;
        int p;
        cin >> x >> y >> p;
        double d = sqrt(x * x + y * y);
        total += 2.0 * d / 50.0 + p + p * 0.5;
    }
    int ans = (int)ceil(total - 1e-9);
    printf("%d\n", ans);
    return 0;
}
