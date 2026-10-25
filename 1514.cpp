#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct P { int t, id; };

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<P> a(n);
    for (int i = 0; i < n; i++) { cin >> a[i].t; a[i].id = i + 1; }
    stable_sort(a.begin(), a.end(), [](const P& x, const P& y) { return x.t < y.t; });
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << a[i].id;
    }
    cout << "\n";
    long long wait = 0, cur = 0;
    for (int i = 0; i < n; i++) {
        wait += cur;
        cur += a[i].t;
    }
    double avg = (double)wait / n;
    cout << fixed << setprecision(2) << avg << "\n";
    return 0;
}
