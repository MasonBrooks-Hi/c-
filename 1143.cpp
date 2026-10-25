#include <iostream>
using namespace std;
bool prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}
int main() {
    for (int i = 100; i <= 999; i++)
        if (prime(i)) cout << i << "\n";
    return 0;
}
