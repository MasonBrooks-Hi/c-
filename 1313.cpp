#include <iostream>
using namespace std;
int main() {
    int y1, m1, d1, y2, m2, d2;
    if (cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2) {
        if (y1 < y2) cout << "Yes" << endl;
        else if (y1 > y2) cout << "No" << endl;
        else if (m1 < m2) cout << "Yes" << endl;
        else if (m1 > m2) cout << "No" << endl;
        else if (d1 < d2) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
