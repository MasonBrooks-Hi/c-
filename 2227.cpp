#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int d, n;
    if (!(cin >> d >> n)) return 0;
    vector<int> x(n), y(n), kk(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> kk[i];
    long long best = -1;
    int cnt = 0;
    for (int cx = 0; cx <= 128; cx++) {
        for (int cy = 0; cy <= 128; cy++) {
            long long s = 0;
            for (int i = 0; i < n; i++) {
                if (abs(x[i] - cx) <= d && abs(y[i] - cy) <= d) s += kk[i];
            }
            if (s > best) { best = s; cnt = 1; }
            else if (s == best) cnt++;
        }
    }
    cout << cnt << " " << best << "\n";
    return 0;
}
