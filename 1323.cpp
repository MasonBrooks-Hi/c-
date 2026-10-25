#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int h, m, s;
    if (cin >> h >> m >> s) {
        double ha = (h % 12) * 30.0 + m * 0.5 + s * (30.0 / 3600.0);
        double ma = m * 6.0 + s * 0.1;
        double diff = fabs(ha - ma);
        if (diff > 180) diff = 360 - diff;
        cout << (int)diff << endl;
    }
    return 0;
}
