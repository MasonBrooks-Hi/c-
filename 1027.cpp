#include <iostream>
using namespace std;
int main() {
    int n, ct, ce;
    if (!(cin >> n)) return 0;
    cin >> ct >> ce;
    double x = (double)ce / ct;
    for (int i = 1; i < n; i++) {
        int t, e;
        cin >> t >> e;
        double y = (double)e / t;
        if (y - x > 0.05) cout << "better\n";
        else if (x - y > 0.05) cout << "worse\n";
        else cout << "same\n";
    }
    return 0;
}
