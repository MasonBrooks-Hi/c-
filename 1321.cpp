#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int r1, c1, r2, c2;
    if (cin >> r1 >> c1 >> r2 >> c2) {
        cout << max(abs(r1 - r2), abs(c1 - c2)) << endl;
    }
    return 0;
}
