#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double x;
    cin >> x;
    double y;
    if (x >= 0 && x < 5) y = -x + 2.5;
    else if (x >= 5 && x < 10) y = 2 - 1.5 * (x - 3) * (x - 3);
    else y = x / 2 - 1.5;
    cout << fixed << setprecision(3) << y << endl;
    return 0;
}
