#include <iostream>
using namespace std;

int main() {
    long long a[15];
    a[1] = 1; a[2] = 2;
    for (int i = 3; i < 15; i++) a[i] = 2 * a[i - 1] + a[i - 2];
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int k;
        cin >> k;
        cout << a[k] << "\n";
    }
    return 0;
}
