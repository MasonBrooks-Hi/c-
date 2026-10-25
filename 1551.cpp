#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, C;
vector<int> x;

bool ok(int dist) {
    int last = x[0], placed = 1;
    for (int i = 1; i < N; i++) {
        if (x[i] - last >= dist) {
            placed++;
            last = x[i];
            if (placed >= C) return true;
        }
    }
    return placed >= C;
}

int main() {
    if (!(cin >> N >> C)) return 0;
    x.resize(N);
    for (int i = 0; i < N; i++) cin >> x[i];
    sort(x.begin(), x.end());
    int lo = 1, hi = x[N - 1] - x[0] + 1, ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (ok(mid)) { ans = mid; lo = mid + 1; }
        else hi = mid - 1;
    }
    cout << ans << "\n";
    return 0;
}
