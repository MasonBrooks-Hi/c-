#include <iostream>
using namespace std;

bool isprime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}

int main() {
    for (int i = 2; i <= 100; i++) {
        if (isprime(i)) {
            int t = i;
            bool has = false;
            while (t > 0) {
                if (t % 10 == 3) has = true;
                t /= 10;
            }
            if (has) cout << i << endl;
        }
    }
    return 0;
}
