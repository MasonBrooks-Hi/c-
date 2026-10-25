#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    if (!(cin >> N)) return 0;
    vector<long long> a(N), pref(N + 1, 0);
    for (int i = 0; i < N; i++) { cin >> a[i]; pref[i + 1] = pref[i] + a[i]; }
    int M;
    cin >> M;
    while (M--) {
        int i, j;
        cin >> i >> j;
        if (i > j) { int t = i; i = j; j = t; }
        long long sum = pref[j] - pref[i - 1];
        int cnt = j - i + 1;
        double avg = (double)sum / cnt;
        printf("%.3lf\n", avg);
    }
    return 0;
}
