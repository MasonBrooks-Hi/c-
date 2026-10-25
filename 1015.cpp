#include <iostream>
using namespace std;
int main() {
    int n, mn = 2000000000, mx = -1, x;
    if (!(cin >> n)) return 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x < mn) mn = x;
        if (x > mx) mx = x;
    }
    cout << mx - mn << "\n";
    return 0;
}
