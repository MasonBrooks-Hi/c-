#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main() {
    double x;
    if (cin >> x) {
        cout << fixed << setprecision(2) << fabs(x) << endl;
    }
    return 0;
}
