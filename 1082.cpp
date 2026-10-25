#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long a[3000];
    for (int i = 0; i < n; i++) cin >> a[i];
    int d[3000];
    for (int i = 0; i < n - 1; i++) {
        long long diff = a[i + 1] - a[i];
        if (diff < 0) diff = -diff;
        d[i] = (int)diff;
    }
    sort(d, d + n - 1);
    bool ok = true;
    for (int i = 0; i < n - 1; i++) if (d[i] != i + 1) { ok = false; break; }
    if (ok) cout << "Jolly\n";
    else cout << "Not jolly\n";
    return 0;
}
