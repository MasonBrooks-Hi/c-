#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) if (x % i == 0) return false;
    return true;
}

int N;
vector<bool> used;
vector<int> pos;
vector<vector<int>> res;

void dfs(int depth) {
    if (depth == N) {
        if (isPrime(pos[N - 1] + pos[0])) res.push_back(pos);
        return;
    }
    for (int num = 2; num <= N; num++) {
        if (used[num]) continue;
        if (isPrime(pos[depth - 1] + num)) {
            used[num] = true;
            pos[depth] = num;
            dfs(depth + 1);
            used[num] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cas = 0;
    int n;
    while (cin >> n) {
        cas++;
        N = n;
        used.assign(n + 1, false);
        pos.assign(n, 0);
        res.clear();
        used[1] = true;
        pos[0] = 1;
        if (N >= 2) dfs(1);
        cout << "Case " << cas << ":\n";
        for (auto& r : res) {
            for (int i = 0; i < N; i++) {
                if (i) cout << " ";
                cout << r[i];
            }
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}
