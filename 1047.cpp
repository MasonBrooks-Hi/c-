#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<int> c(n + 1);
    for (int i = n; i >= 0; i--) cin >> c[i];
    if (n == 0) { cout << 0 << "\n"; return 0; }
    for (int i = n - 1; i >= 0; i--) {
        if (i < n - 1) cout << " ";
        cout << c[i + 1] * (i + 1);
    }
    cout << "\n";
    return 0;
}
