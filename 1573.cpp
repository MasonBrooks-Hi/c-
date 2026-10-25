#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    double a, b;
    if (!(cin >> a >> b)) return 0;
    double r = fmod(a, b);
    if (r < 0) r += b;
    cout << fixed << setprecision(4) << r << "\n";
    return 0;
}
