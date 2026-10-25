// 1877 Fish学数学
// Total count of pairs (i<j) with a[i] > a[j] (inversions).
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    long long cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j]) cnt++;
    printf("%lld\n", cnt);
    return 0;
}
