#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> c;

bool ok(int limit) {
    int groups = 1, cur = 0;
    for (int i = 0; i < N; i++) {
        if (cur + c[i] > limit) {
            groups++;
            cur = c[i];
            if (groups > M) return false;
        } else cur += c[i];
    }
    return true;
}

int main() {
    if (!(cin >> N >> M)) return 0;
    c.resize(N);
    int maxc = 0;
    long long sum = 0;
    for (int i = 0; i < N; i++) { cin >> c[i]; maxc = max(maxc, c[i]); sum += c[i]; }
    int lo = maxc, hi = (int)sum, ans = (int)sum;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (ok(mid)) { ans = mid; hi = mid - 1; }
        else lo = mid + 1;
    }
    cout << ans << "\n";
    return 0;
}
