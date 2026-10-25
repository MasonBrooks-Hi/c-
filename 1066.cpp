#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int d;
    cin >> d;
    double bike = 50.0 + d / 3.0;
    double walk = d / 1.2;
    if (fabs(bike - walk) < 1e-9) cout << "All\n";
    else if (bike < walk) cout << "Bike\n";
    else cout << "Walk\n";
    return 0;
}
