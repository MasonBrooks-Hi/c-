#include <iostream>
using namespace std;

bool isprime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}

bool isnarc(int x) {
    int t = x, s = 0;
    while (t > 0) {
        int d = t % 10;
        s += d * d * d;
        t /= 10;
    }
    return s == x;
}

int main() {
    bool any = false;
    for (int i = 100; i <= 999; i++) {
        if (isprime(i) && isnarc(i)) {
            cout << i << endl;
            any = true;
        }
    }
    if (!any) cout << "None" << endl;
    return 0;
}
