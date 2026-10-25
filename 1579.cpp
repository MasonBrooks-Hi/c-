#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double x, a, y, b;
    if (!(cin >> x >> a >> y >> b)) return 0;
    double g = (y * b - x * a) / (b - a);
    cout << fixed << setprecision(2) << g << "\n";
    return 0;
}
