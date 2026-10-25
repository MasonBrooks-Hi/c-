#include <iostream>
using namespace std;
bool isLeap(int y) { return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0); }
int main() {
    int y, m;
    if (cin >> y >> m) {
        int days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        if (isLeap(y)) days[2] = 29;
        cout << days[m] << endl;
    }
    return 0;
}
