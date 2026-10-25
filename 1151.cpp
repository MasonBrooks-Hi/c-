#include <iostream>
using namespace std;
bool prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}
int main() {
    int s = 0;
    for (int i = 2; i <= 100; i++)
        if (prime(i)) s += i;
    cout << s << "\n";
    return 0;
}
