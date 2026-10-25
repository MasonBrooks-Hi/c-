#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    if (!(cin >> n >> m)) return 0;
    string a, b;
    cin >> a >> b;
    sort(b.rbegin(), b.rend());
    for (int i = 0; i < n; i++) {
        if (!b.empty() && b[0] > a[i]) {
            a[i] = b[0];
            b.erase(b.begin());
        }
    }
    cout << a << "\n";
    return 0;
}
