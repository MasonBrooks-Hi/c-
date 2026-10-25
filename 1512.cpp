#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
vector<string> w;
vector<int> used;
string st;
int ans = 0;

int overlap(const string& a, const string& b) {
    int la = (int)a.size(), lb = (int)b.size();
    int lim = min(la, lb);
    for (int k = lim; k >= 1; k--) {
        if (k == la || k == lb) continue; // 不允许包含关系
        if (a.substr(la - k, k) == b.substr(0, k)) return k;
    }
    return 0;
}

void dfs(int cur, int len) {
    ans = max(ans, len);
    for (int i = 0; i < n; i++) {
        if (used[i] >= 2) continue;
        int ov = overlap(w[cur], w[i]);
        if (ov > 0) {
            used[i]++;
            dfs(i, len + (int)w[i].size() - ov);
            used[i]--;
        }
    }
}

int main() {
    if (!(cin >> n)) return 0;
    w.resize(n);
    for (int i = 0; i < n; i++) cin >> w[i];
    cin >> st;
    used.assign(n, 0);
    ans = 0;
    for (int i = 0; i < n; i++) {
        if (w[i][0] == st[0]) {
            used[i]++;
            dfs(i, (int)w[i].size());
            used[i]--;
        }
    }
    cout << ans << "\n";
    return 0;
}
