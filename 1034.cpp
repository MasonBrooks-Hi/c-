#include <iostream>
using namespace std;
int main() {
    for (int a = 1; a <= 6; a++) {
        for (int c = 1; c <= 8; c++) {
            int b = 24 * a - 40 * c;
            if (b >= 0 && b <= 6) {
                int N = 49 * a + 7 * b + c;
                int d0 = N % 9, d1 = (N / 9) % 9, d2 = N / 81;
                if (d0 == a && d1 == b && d2 == c) {
                    cout << N << "\n";
                    cout << a << b << c << "\n";
                    cout << c << b << a << "\n";
                }
            }
        }
    }
    return 0;
}
