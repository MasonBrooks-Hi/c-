// 1861 下载电影
// Max average speed over any window of M consecutive hours, 2 decimal places.
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<long long> v(n);
    for (auto &x : v) cin >> x;
    long long sum = 0;
    for (int i = 0; i < m; i++) sum += v[i];
    long long best = sum;
    for (int i = m; i < n; i++) {
        sum += v[i] - v[i - m];
        if (sum > best) best = sum;
    }
    printf("%.2f\n", (double)best / m);
    return 0;
}
