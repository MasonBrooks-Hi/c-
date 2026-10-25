#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, N, M;
vector<int> d;

bool ok(int dist) {
    int last = 0, removed = 0;
    for (int i = 0; i < N; i++) {
        if (d[i] - last < dist) removed++;
        else last = d[i];
    }
    if (L - last < dist) return false;
    return removed <= M;
}

int main() {
    if (!(cin >> L >> N >> M)) return 0;
    d.resize(N);
    for (int i = 0; i < N; i++) cin >> d[i];
    sort(d.begin(), d.end());
    int lo = 1, hi = L, ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (ok(mid)) { ans = mid; lo = mid + 1; }
        else hi = mid - 1;
    }
    cout << ans << "\n";
    return 0;
}
