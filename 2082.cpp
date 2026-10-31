#include <iostream>
using namespace std;

int main() {
    int y, m, d;
    if (!(cin >> y >> m >> d)) return 0;
    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) days[2] = 29;
    int sum = d;
    for (int i = 1; i < m; i++) sum += days[i];
    cout << sum << '\n';
    return 0;
}
