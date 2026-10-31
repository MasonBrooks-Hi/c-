#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    if (!(cin >> N)) return 0;
    vector<int> c(N);
    for (int i = 0; i < N; i++) cin >> c[i];
    sort(c.rbegin(), c.rend());
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        if (i % 3 != 2) ans += c[i];
    }
    cout << ans << "\n";
    return 0;
}
