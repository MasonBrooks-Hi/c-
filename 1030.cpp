#include <iostream>
using namespace std;
int main() {
    long long n;
    if (!(cin >> n)) return 0;
    while (n != 1) {
        if (n % 2 == 1) {
            long long t = n * 3 + 1;
            cout << n << "*3+1=" << t << "\n";
            n = t;
        } else {
            long long t = n / 2;
            cout << n << "/2=" << t << "\n";
            n = t;
        }
    }
    cout << "End\n";
    return 0;
}
