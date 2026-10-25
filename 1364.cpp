#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, m, best;
vector<string> g;
bool used[26];

void dfs(int i, int j, int cnt) {
    if (cnt > best) best = cnt;
    int di[] = {-1, 1, 0, 0};
    int dj[] = {0, 0, -1, 1};
    for (int d = 0; d < 4; d++) {
        int ni = i + di[d], nj = j + dj[d];
        if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
            int c = g[ni][nj] - 'A';
            if (!used[c]) {
                used[c] = true;
                dfs(ni, nj, cnt + 1);
                used[c] = false;
            }
        }
    }
}

int main() {
    if (!(cin >> n >> m)) return 0;
    g.resize(n);
    for (int i = 0; i < n; i++) cin >> g[i];
    used[g[0][0] - 'A'] = true;
    dfs(0, 0, 1);
    cout << best << "\n";
    return 0;
}
