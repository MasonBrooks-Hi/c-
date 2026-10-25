#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Game { int t, w; };
bool cmp(const Game& a, const Game& b) { return a.w > b.w; }

int main() {
    long long m;
    int n;
    if (!(cin >> m >> n)) return 0;
    vector<Game> g(n);
    for (int i = 0; i < n; i++) cin >> g[i].t;
    for (int i = 0; i < n; i++) cin >> g[i].w;
    sort(g.begin(), g.end(), cmp);
    vector<bool> used(n + 1, false);
    long long penalty = 0;
    for (int i = 0; i < n; i++) {
        bool placed = false;
        for (int t = g[i].t; t >= 1; t--) {
            if (!used[t]) { used[t] = true; placed = true; break; }
        }
        if (!placed) penalty += g[i].w;
    }
    cout << m - penalty << "\n";
    return 0;
}
