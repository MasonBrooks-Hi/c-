#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double x;
    if (!(cin >> x)) return 0;
    cout << fixed << setprecision(3) << x << "\n";
    return 0;
}
