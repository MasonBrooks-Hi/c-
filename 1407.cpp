#include <iostream>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    long long total = 0;
    for (int i = 0; i < n; i++) {
        int k, a, b, c;
        cin >> k;
        if (k == 1) { cin >> a >> b; total += 2LL * (a + b); }
        else if (k == 2) { cin >> a; total += 4LL * a; }
        else { cin >> a >> b >> c; total += (long long)(a + b + c); }
    }
    cout << total << "\n";
    return 0;
}
