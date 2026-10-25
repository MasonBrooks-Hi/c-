#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<int> sums(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x < 0) x = -x;
        int s = 0;
        if (x == 0) s = 0;
        while (x) {
            s += x % 10;
            x /= 10;
        }
        sums[i] = s;
    }
    sort(sums.begin(), sums.end());
    for (int i = 0; i < n; i++) {
        if (i) cout << ' ';
        cout << sums[i];
    }
    cout << '\n';
    return 0;
}
