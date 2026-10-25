#include <iostream>
using namespace std;
int main() {
    int x;
    if (cin >> x) {
        if (x > 0) cout << x + 1 << endl;
        else if (x == 0) cout << 0 << endl;
        else cout << x - 1 << endl;
    }
    return 0;
}
