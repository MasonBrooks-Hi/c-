#include <iostream>
using namespace std;
int main() {
    int n;
    if (!(cin >> n)) return 0;
    while (n > 0) {
        cout << n % 10 << " ";
        n /= 10;
    }
    cout << "\n";
    return 0;
}
