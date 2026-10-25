#include <iostream>
using namespace std;

int main() {
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        long long n;
        cin >> n;
        long long d = (n * n) % 10000;
        cout << d << "\n";
    }
    return 0;
}
