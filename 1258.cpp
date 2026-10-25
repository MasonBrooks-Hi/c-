#include <iostream>
using namespace std;

int main() {
    int q;
    if (!(cin >> q)) return 0;
    int price = (q > 100) ? 50 : 80;
    cout << q * price << "\n";
    return 0;
}
