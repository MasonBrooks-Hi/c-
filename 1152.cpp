#include <iostream>
using namespace std;
int main() {
    long long n;
    cin >> n;
    long long r = 0;
    while (n > 0) { r = r * 10 + n % 10; n /= 10; }
    cout << r << "\n";
    return 0;
}
