#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<long long> f(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        f[i] = 1;
        for (int d = 2; d < i; d++) {
            if (i % d == 0) f[i] += f[i / d];
        }
    }
    cout << f[n] << "\n";
    return 0;
}
