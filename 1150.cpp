#include <iostream>
using namespace std;
bool prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}
int main() {
    for (int x = 10; x <= 99; x++) {
        int rev = x % 10 * 10 + x / 10;
        if (prime(x) && prime(rev) && x <= rev)
            cout << x << " " << rev << "\n";
    }
    return 0;
}
