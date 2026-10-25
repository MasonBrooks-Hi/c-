#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    double x;
    cin >> x;
    cout << fixed << setprecision(2) << fabs(x) << endl;
    return 0;
}
