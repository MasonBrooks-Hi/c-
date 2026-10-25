#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int h, r;
    cin >> h >> r;
    double pi = 3.14159;
    double v = pi * r * r * h;
    int ans = (int)ceil(20000.0 / v);
    cout << ans << endl;
    return 0;
}
