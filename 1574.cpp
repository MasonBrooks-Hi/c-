#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int h, r;
    if (!(cin >> h >> r)) return 0;
    double vol = 3.14159 * r * r * h;
    int ans = (int)ceil(20000.0 / vol);
    cout << ans << "\n";
    return 0;
}
