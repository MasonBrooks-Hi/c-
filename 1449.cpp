#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m, n;
    if (!(cin >> m >> n)) return 0;
    vector<int> spf(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        if (spf[i] == 0) {
            for (int j = i; j <= n; j += i)
                if (spf[j] == 0) spf[j] = i;
        }
    }
    bool first = true;
    for (int x = m; x <= n; x++) {
        int t = x, lpf = 1;
        while (t > 1) { lpf = spf[t]; t /= spf[t]; }
        if (!first) cout << ",";
        cout << lpf;
        first = false;
    }
    cout << "\n";
    return 0;
}
