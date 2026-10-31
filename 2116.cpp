#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    if (!(cin >> N >> M)) return 0;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    vector<int> b(M);
    int cnt[5] = {0, 0, 0, 0, 0};
    for (int i = 0; i < M; i++) { cin >> b[i]; cnt[b[i]]++; }
    int d1 = cnt[1] + 1, d2 = cnt[2] + 1, d3 = cnt[3] + 1, d4 = cnt[4] + 1;
    vector<int> dp(d1 * d2 * d3 * d4, -1);
    auto id = [&](int i1, int i2, int i3, int i4) {
        return (((i1 * d2 + i2) * d3 + i3) * d4 + i4);
    };
    dp[id(0, 0, 0, 0)] = a[0];
    int ans = 0;
    for (int i1 = 0; i1 <= cnt[1]; i1++)
        for (int i2 = 0; i2 <= cnt[2]; i2++)
            for (int i3 = 0; i3 <= cnt[3]; i3++)
                for (int i4 = 0; i4 <= cnt[4]; i4++) {
                    int idx = id(i1, i2, i3, i4);
                    int cur = dp[idx];
                    if (cur < 0) continue;
                    int pos = i1 + 2 * i2 + 3 * i3 + 4 * i4;
                    if (pos == N - 1) { if (cur > ans) ans = cur; }
                    if (i1 < cnt[1]) {
                        int np = pos + 1;
                        int nidx = id(i1 + 1, i2, i3, i4);
                        if (cur + a[np] > dp[nidx]) dp[nidx] = cur + a[np];
                    }
                    if (i2 < cnt[2]) {
                        int np = pos + 2;
                        int nidx = id(i1, i2 + 1, i3, i4);
                        if (cur + a[np] > dp[nidx]) dp[nidx] = cur + a[np];
                    }
                    if (i3 < cnt[3]) {
                        int np = pos + 3;
                        int nidx = id(i1, i2, i3 + 1, i4);
                        if (cur + a[np] > dp[nidx]) dp[nidx] = cur + a[np];
                    }
                    if (i4 < cnt[4]) {
                        int np = pos + 4;
                        int nidx = id(i1, i2, i3, i4 + 1);
                        if (cur + a[np] > dp[nidx]) dp[nidx] = cur + a[np];
                    }
                }
    cout << ans << '\n';
    return 0;
}
