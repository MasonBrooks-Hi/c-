#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int R, M, Y;
    if (!(cin >> R >> M >> Y)) return 0;
    double v = M;
    for (int i = 0; i < Y; i++) v *= 1 + R / 100.0;
    long long r = (long long)(v - 1e-9);
    cout << r << "\n";
    return 0;
}
