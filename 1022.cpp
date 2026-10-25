#include <iostream>
using namespace std;
int main() {
    long long a, n, res = 1;
    if (!(cin >> a >> n)) return 0;
    for (long long i = 0; i < n; i++) res *= a;
    cout << res << "\n";
    return 0;
}
