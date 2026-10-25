#include <iostream>
using namespace std;

int main() {
    int D, I;
    if (!(cin >> D >> I)) return 0;
    int k = 1;
    for (int i = 1; i < D; i++) {
        if (I % 2 == 1) {
            k = k * 2;
            I = (I + 1) / 2;
        } else {
            k = k * 2 + 1;
            I = I / 2;
        }
    }
    cout << k << "\n";
    return 0;
}
