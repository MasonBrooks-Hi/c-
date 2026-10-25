#include <iostream>
using namespace std;
int main() {
    int N;
    cin >> N;
    for (int a = 2; a <= N; a++) {
        long long a3 = (long long)a * a * a;
        for (int b = 2; b < a; b++) {
            for (int c = b; c < a; c++) {
                for (int d = c; d < a; d++) {
                    long long sum = (long long)b * b * b + (long long)c * c * c + (long long)d * d * d;
                    if (sum > a3) break;
                    if (sum == a3)
                        cout << "Cube = " << a << ", Triple = (" << b << "," << c << "," << d << ")\n";
                }
            }
        }
    }
    return 0;
}
