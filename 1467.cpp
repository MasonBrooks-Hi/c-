#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<int> parent(n + 1, 0);
    vector<vector<int>> children(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        children[x].push_back(y);
        parent[y] = x;
    }
    int root = 0;
    for (int i = 1; i <= n; i++)
        if (parent[i] == 0) { root = i; break; }
    int maxNode = 0, maxCnt = -1;
    for (int i = 1; i <= n; i++) {
        if ((int)children[i].size() > maxCnt) {
            maxCnt = (int)children[i].size();
            maxNode = i;
        }
    }
    sort(children[maxNode].begin(), children[maxNode].end());
    cout << root << "\n";
    cout << maxNode << "\n";
    for (size_t i = 0; i < children[maxNode].size(); i++) {
        if (i) cout << " ";
        cout << children[maxNode][i];
    }
    cout << "\n";
    return 0;
}
