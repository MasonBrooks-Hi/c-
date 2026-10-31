#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int M, N;
    if (!(cin >> M >> N)) return 0;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    sort(a.rbegin(), a.rend());
    int k = min(M, N / 2);
    long long ans = 0;
    for (int i = 0; i < k; i++) ans += a[i] - a[N - 1 - i];
    cout << ans << "\n";
    return 0;
}
