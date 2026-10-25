#include <iostream>
using namespace std;

int main() {
    int m;
    if (!(cin >> m)) return 0;
    while (m--) {
        long long n, b;
        cin >> n >> b;
        cout << n / b << "\n";
    }
    return 0;
}
