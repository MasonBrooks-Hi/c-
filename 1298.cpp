#include <iostream>
using namespace std;
int main() {
    int p, q, m;
    if (cin >> p >> q >> m) {
        if (m >= p && m <= q) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
