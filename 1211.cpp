#include <iostream>
using namespace std;

int main() {
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long H;
        cin >> H;
        long long d;
        if (H <= 10) {
            d = 1;
        } else {
            d = (H - 10 + 4) / 5 + 1;
        }
        cout << d << "\n";
    }
    return 0;
}
