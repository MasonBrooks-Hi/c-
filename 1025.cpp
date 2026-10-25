#include <iostream>
using namespace std;
int main() {
    int N, K;
    if (!(cin >> N >> K)) return 0;
    double save = 0, price = 200;
    int year = 0, ok = 0;
    for (int y = 1; y <= 20; y++) {
        save += N;
        if (save >= price) { year = y; ok = 1; break; }
        price *= 1 + K / 100.0;
    }
    if (ok) cout << year << "\n";
    else cout << "Impossible\n";
    return 0;
}
