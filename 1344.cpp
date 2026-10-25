#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<string> g(n);
    for (int i = 0; i < n; i++) cin >> g[i];
    int m;
    cin >> m;
    // simulate m-1 days of infection (day 1 is initial state)
    for (int day = 1; day < m; day++) {
        vector<pair<int,int>> infected;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (g[i][j] == '@') {
                    int di[] = {-1, 1, 0, 0};
                    int dj[] = {0, 0, -1, 1};
                    for (int d = 0; d < 4; d++) {
                        int ni = i + di[d], nj = j + dj[d];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n && g[ni][nj] == '.')
                            infected.emplace_back(ni, nj);
                    }
                }
        for (auto &p : infected) g[p.first][p.second] = '@';
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (g[i][j] == '@') cnt++;
    cout << cnt << "\n";
    return 0;
}
