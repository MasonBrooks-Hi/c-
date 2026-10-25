#include <iostream>
using namespace std;

bool isPalindrome(int x) {
    int t = x, r = 0;
    while (t) { r = r * 10 + t % 10; t /= 10; }
    return r == x;
}

int main() {
    for (int x = 10000; x <= 99999; x++) {
        if (isPalindrome(x) && x % 11 == 0)
            cout << x << "\n";
    }
    return 0;
}
