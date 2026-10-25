#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> path;

void dfs(int last, int remain) {
    if (remain == 0) {
        cout << n << "=" << path[0];
        for (size_t i = 1; i < path.size(); i++) cout << "+" << path[i];
        cout << "\n";
        return;
    }
    for (int i = last; i <= remain; i++) {
        if (i >= n) break; // each part must be < n
        path.push_back(i);
        dfs(i, remain - i);
        path.pop_back();
    }
}

int main() {
    if (!(cin >> n)) return 0;
    dfs(1, n);
    return 0;
}
