#include <iostream>
using namespace std;
int main() {
    int K;
    if (!(cin >> K)) return 0;
    double s = 0;
    int n = 0;
    while (s <= K) { n++; s += 1.0 / n; }
    cout << n << "\n";
    return 0;
}
