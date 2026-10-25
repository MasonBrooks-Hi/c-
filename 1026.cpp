#include <iostream>
using namespace std;
int main() {
    int k;
    if (!(cin >> k)) return 0;
    long long a = 1, b = 1;
    if (k == 1 || k == 2) { cout << 1 << "\n"; return 0; }
    for (int i = 3; i <= k; i++) { long long t = a + b; a = b; b = t; }
    cout << b << "\n";
    return 0;
}
