#include <iostream>
using namespace std;
int main() {
    int n, m, x, c = 0;
    if (!(cin >> n >> m)) return 0;
    for (int i = 0; i < n; i++) { cin >> x; if (x == m) c++; }
    cout << c << "\n";
    return 0;
}
