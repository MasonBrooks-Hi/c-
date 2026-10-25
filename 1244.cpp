#include <iostream>
using namespace std;

int main() {
    int nn;
    if (!(cin >> nn)) return 0;
    while (nn--) {
        int a, b, c;
        cin >> a >> b >> c;
        bool found = false;
        for (int x = 1000; x <= 9999; x++) {
            if (x % a == 0 && (x + 1) % b == 0 && (x + 2) % c == 0) {
                cout << x << "\n";
                found = true;
                break;
            }
        }
        if (!found) cout << "Impossible\n";
    }
    return 0;
}
