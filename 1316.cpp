#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    double f;
    if (cin >> f) {
        double w;
        if (f <= 15.0) w = f / 1.5;
        else w = 10 + (f - 15) / 2.5;
        cout << fixed << setprecision(2) << w << endl;
    }
    return 0;
}
