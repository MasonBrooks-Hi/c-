#include <iostream>
#include <vector>
using namespace std;

int n, r;
vector<int> cur;

void dfs(int start) {
    if ((int)cur.size() == r) {
        for (int i = 0; i < (int)cur.size(); i++) cout << " " << cur[i];
        cout << "\n";
        return;
    }
    int need = r - (int)cur.size();
    for (int i = start; i <= n - need + 1; i++) {
        cur.push_back(i);
        dfs(i + 1);
        cur.pop_back();
    }
}

int main() {
    if (!(cin >> n >> r)) return 0;
    dfs(1);
    return 0;
}
