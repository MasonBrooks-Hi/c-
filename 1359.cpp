#include <iostream>
using namespace std;

int main() {
    long long f[35];
    f[1] = 1; f[2] = 2;
    for (int i = 3; i < 35; i++) f[i] = f[i - 1] + f[i - 2];
    int N;
    while (cin >> N) cout << f[N] << "\n";
    return 0;
}
