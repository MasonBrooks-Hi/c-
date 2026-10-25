#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    if (n <= 0) return 0;
    vector<long long> ugly(n);
    ugly[0] = 1;
    int i2 = 0, i3 = 0, i5 = 0;
    for (int i = 1; i < n; i++) {
        long long next = min({ugly[i2] * 2, ugly[i3] * 3, ugly[i5] * 5});
        ugly[i] = next;
        if (next == ugly[i2] * 2) i2++;
        if (next == ugly[i3] * 3) i3++;
        if (next == ugly[i5] * 5) i5++;
    }
    cout << ugly[n - 1] << '\n';
    return 0;
}
