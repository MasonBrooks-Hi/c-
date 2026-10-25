#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int A = 0, B = 0;
    for (int x = 1; x <= 1000; x++) {
        int ones = 0, zeros = 0;
        int t = x;
        while (t > 0) {
            if (t % 2 == 1) ones++;
            else zeros++;
            t /= 2;
        }
        if (ones > zeros) A++;
        else B++;
    }
    cout << A << " " << B << "\n";
    return 0;
}
