#include <iostream>
using namespace std;
int main() {
    int m, n, c = 0, x;
    if (!(cin >> m >> n)) return 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x > m) c++;
        else m -= x;
    }
    cout << c << "\n";
    return 0;
}
