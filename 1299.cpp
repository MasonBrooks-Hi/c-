#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    double h;
    if (cin >> h) {
        if (h < 1.3) cout << 60 << endl;
        else cout << 120 << endl;
    }
    return 0;
}
