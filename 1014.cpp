#include <iostream>
using namespace std;
int main() {
    int n, mx = -1, x;
    if (!(cin >> n)) return 0;
    for (int i = 0; i < n; i++) { cin >> x; if (x > mx) mx = x; }
    cout << mx << "\n";
    return 0;
}
