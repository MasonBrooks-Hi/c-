#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double p[11] = {0, 28.9, 32.7, 45.6, 78, 35, 86.2, 27.8, 43, 56, 65};
    double sum = 0;
    for (int i = 1; i <= 10; i++) {
        int q;
        cin >> q;
        sum += p[i] * q;
    }
    cout << fixed << setprecision(1) << sum << endl;
    return 0;
}
