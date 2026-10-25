#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;
    double delta = b * b - 4 * a * c;
    cout << fixed << setprecision(5);
    auto norm0 = [](double v) { return (fabs(v) < 1e-9) ? 0.0 : v; };
    if (fabs(delta) < 1e-9) {
        double x = norm0(-b / (2 * a));
        cout << "x1=x2=" << x << endl;
    } else if (delta > 0) {
        double sq = sqrt(delta);
        double x1 = (-b + sq) / (2 * a);
        double x2 = (-b - sq) / (2 * a);
        if (x1 < x2) { double t = x1; x1 = x2; x2 = t; }
        cout << "x1=" << x1 << ";x2=" << x2 << endl;
    } else {
        double real = norm0(-b / (2 * a));
        double imag = sqrt(-delta) / fabs(2 * a);
        cout << "x1=" << real << "+" << imag << "i;x2=" << real << "-" << imag << "i" << endl;
    }
    return 0;
}
