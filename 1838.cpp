// 1838 相加之和最大
// Circular array: max sum of 4 consecutive numbers; output sum and 1-based start position.
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<long long> a(n);
    for (auto &x : a) cin >> x;
    long long best = 0;
    int pos = 1;
    for (int i = 0; i < n; i++) {
        long long s = a[i] + a[(i + 1) % n] + a[(i + 2) % n] + a[(i + 3) % n];
        if (i == 0 || s > best) { best = s; pos = i + 1; }
    }
    printf("%lld\n%d\n", best, pos);
    return 0;
}
