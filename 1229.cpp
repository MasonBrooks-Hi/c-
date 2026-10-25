#include <iostream>
using namespace std;

int main() {
    unsigned long long k, x, y;
    if (!(cin >> k >> x >> y)) return 0;
    x--;
    y--;
    unsigned long long X = x, Y = y;
    int pc = __builtin_popcountll(X & Y);
    int v = (pc % 2 == 0) ? 1 : 0;
    cout << v << "\n";
    return 0;
}
