#include <iostream>
using namespace std;
bool isLeap(int y) { return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0); }
int daysIn(int y, int m) {
    int d[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if (m == 2 && isLeap(y)) return 29;
    return d[m];
}
int main() {
    int m, d, y;
    if (cin >> m >> d >> y) {
        d++;
        if (d > daysIn(y, m)) { d = 1; m++; if (m > 12) { m = 1; y++; } }
        cout << m << "/" << d << "/" << y << endl;
    }
    return 0;
}
