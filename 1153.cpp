#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main() {
    int m, n;
    cin >> m >> n;
    double ratio = pow(2.0, (double)(n - m));
    cout << fixed << setprecision(7) << ratio << "\n";
    return 0;
}
