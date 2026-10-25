#include <iostream>
using namespace std;
int main() {
    int m, n, s = 0;
    if (!(cin >> m >> n)) return 0;
    for (int i = m; i <= n; i++) if (i % 17 == 0) s += i;
    cout << s << "\n";
    return 0;
}
