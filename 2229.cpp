#include <iostream>
using namespace std;

bool isLeap(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int y, m;
    if (!(cin >> y >> m)) return 0;
    int days;
    if (m == 2) days = isLeap(y) ? 29 : 28;
    else if (m == 4 || m == 6 || m == 9 || m == 11) days = 30;
    else days = 31;
    cout << days << "\n";
    return 0;
}
