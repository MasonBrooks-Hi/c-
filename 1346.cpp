#include <iostream>
using namespace std;

int main() {
    long long f[25];
    f[1] = 1; f[2] = 2;
    for (int i = 3; i < 25; i++) f[i] = f[i - 1] + f[i - 2];
    int N;
    if (cin >> N) cout << f[N] << "\n";
    return 0;
}
