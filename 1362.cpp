#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int n, r;
vector<int> ans;

void dfs(int start, int cnt) {
    if (cnt == r) {
        for (int i = 0; i < r; i++) printf("%3d", ans[i]);
        printf("\n");
        return;
    }
    for (int i = start; i <= n - (r - cnt) + 1; i++) {
        ans.push_back(i);
        dfs(i + 1, cnt + 1);
        ans.pop_back();
    }
}

int main() {
    if (!(cin >> n >> r)) return 0;
    dfs(1, 0);
    return 0;
}
