#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    unsigned long long n;
    if (!(cin >> n)) return 0;
    int c4 = 0, c7 = 0;
    while (n % 4 == 0) { n /= 4; c4++; }
    while (n % 7 == 0) { n /= 7; c7++; }
    cout << c4 << " " << c7 << "\n";
    return 0;
}
