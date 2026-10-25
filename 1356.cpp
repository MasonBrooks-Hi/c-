#include <iostream>
using namespace std;

int main() {
    long long f[25];
    f[1] = 1; f[2] = 1;
    for (int i = 3; i < 25; i++) f[i] = f[i - 1] + f[i - 2];
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int a;
        cin >> a;
        cout << f[a] << "\n";
    }
    return 0;
}
