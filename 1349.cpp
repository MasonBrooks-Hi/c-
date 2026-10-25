#include <iostream>
using namespace std;

int main() {
    long long f[25];
    f[1] = 3; f[2] = 7;
    for (int i = 3; i < 25; i++) f[i] = 2 * f[i - 1] + f[i - 2];
    int n;
    if (cin >> n) cout << f[n] << "\n";
    return 0;
}
