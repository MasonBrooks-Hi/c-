#include <iostream>
using namespace std;
int main() {
    int m, k;
    if (!(cin >> m >> k)) return 0;
    int cnt = 0, t = m;
    while (t > 0) { if (t % 10 == 3) cnt++; t /= 10; }
    if (m % 19 == 0 && cnt == k) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
