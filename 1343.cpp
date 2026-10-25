#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int MAX = 40;
    long long f[MAX];
    f[0] = 1; f[1] = 1; f[2] = 2; f[3] = 4;
    for (int i = 4; i < MAX; i++)
        f[i] = f[i - 1] + f[i - 2] + f[i - 3];
    int n;
    while (cin >> n && n != 0)
        cout << f[n] << "\n";
    return 0;
}
