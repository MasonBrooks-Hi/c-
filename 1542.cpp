#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double f(double x) {
    return x * x * x * x * x - 15 * x * x * x * x + 85 * x * x * x - 225 * x * x + 274 * x - 121;
}

int main() {
    double lo = 1.5, hi = 2.4;
    for (int i = 0; i < 100; i++) {
        double mid = (lo + hi) / 2;
        if (f(mid) > 0) lo = mid;
        else hi = mid;
    }
    cout << fixed << setprecision(6) << lo << "\n";
    return 0;
}
