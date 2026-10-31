#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<int> t(n);
    for (int i = 0; i < n; i++) cin >> t[i];
    sort(t.begin(), t.end());
    vector<vector<int>> taps(m);
    for (int i = 0; i < n; i++) taps[i % m].push_back(t[i]);
    long long total = 0;
    for (int i = 0; i < m; i++) {
        long long cum = 0;
        for (int x : taps[i]) {
            cum += x;
            total += cum;
        }
    }
    cout << total << '\n';
    return 0;
}
