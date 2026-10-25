#include <iostream>
using namespace std;

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;
    long long ans = (long long)(n + 1);
    for (int i = 0; i < m; i++) ans *= 2;
    cout << ans << "\n";
    return 0;
}
