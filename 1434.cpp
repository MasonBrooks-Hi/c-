#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    if (!(cin >> N >> M)) return 0;
    vector<string> g(N);
    for (int i = 0; i < N; i++) cin >> g[i];
    vector<vector<int>> base(N, vector<int>(M));
    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++)
            base[r][c] = (g[r][c] == 'X') ? 1 : 0;

    auto shoot = [&](vector<vector<int>>& cur, int r, int c) {
        if (r >= 0 && r < N && c >= 0 && c < M) cur[r][c] ^= 1;
        if (r - 1 >= 0 && c >= 0 && c < M) cur[r - 1][c] ^= 1;
        if (r + 1 < N && c >= 0 && c < M) cur[r + 1][c] ^= 1;
        if (r >= 0 && r < N && c - 1 >= 0) cur[r][c - 1] ^= 1;
        if (r >= 0 && r < N && c + 1 < M) cur[r][c + 1] ^= 1;
    };

    int ans = 1e9;
    int masks = 1 << M;
    for (int mask = 0; mask < masks; mask++) {
        vector<vector<int>> cur = base;
        int shots = 0;
        for (int c = 0; c < M; c++)
            if ((mask >> c) & 1) { shots++; shoot(cur, 0, c); }
        for (int r = 1; r < N; r++) {
            for (int c = 0; c < M; c++) {
                if (cur[r - 1][c] == 1) { shots++; shoot(cur, r, c); }
            }
        }
        bool ok = true;
        for (int c = 0; c < M; c++)
            if (cur[N - 1][c] != 0) { ok = false; break; }
        if (ok && shots < ans) ans = shots;
    }
    cout << ans << "\n";
    return 0;
}
