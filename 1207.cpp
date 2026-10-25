#include <iostream>
using namespace std;

int main() {
    int m;
    if (!(cin >> m)) return 0;
    while (m--) {
        int n;
        cin >> n;
        long long x = 1;
        for (int i = 0; i < n; i++) {
            x = (x + 1) * 2;
        }
        cout << x << "\n";
    }
    return 0;
}
