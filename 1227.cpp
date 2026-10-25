#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> grid;
vector<int> rowsum, colsum;
vector<pair<int, int>> empties;
int rowcur[10], colcur[10];
bool rowused[10][10], colused[10][10];
int cnt;
vector<vector<int>> sol;

void dfs(int idx) {
    if (cnt > 1) return;
    if (idx == (int)empties.size()) {
        for (int i = 1; i <= n; i++)
            if (rowcur[i] != rowsum[i]) return;
        for (int j = 1; j <= m; j++)
            if (colcur[j] != colsum[j]) return;
        cnt++;
        if (cnt == 1) sol = grid;
        return;
    }
    int x = empties[idx].first;
    int y = empties[idx].second;
    for (int d = 1; d <= 9; d++) {
        if (rowused[x][d] || colused[y][d]) continue;
        if (rowcur[x] + d > rowsum[x]) continue;
        if (colcur[y] + d > colsum[y]) continue;
        grid[x][y] = d;
        rowcur[x] += d;
        colcur[y] += d;
        rowused[x][d] = true;
        colused[y][d] = true;
        dfs(idx + 1);
        rowcur[x] -= d;
        colcur[y] -= d;
        rowused[x][d] = false;
        colused[y][d] = false;
        grid[x][y] = 0;
    }
}

int main() {
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        cin >> n >> m;
        rowsum.assign(n + 1, 0);
        colsum.assign(m + 1, 0);
        for (int i = 1; i <= n; i++) cin >> rowsum[i];
        for (int j = 1; j <= m; j++) cin >> colsum[j];
        grid.assign(n + 1, vector<int>(m + 1, 0));
        empties.clear();
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) cin >> grid[i][j];
        for (int i = 0; i <= n; i++)
            for (int d = 0; d <= 9; d++) rowused[i][d] = false;
        for (int j = 0; j <= m; j++)
            for (int d = 0; d <= 9; d++) colused[j][d] = false;
        for (int i = 1; i <= n; i++) rowcur[i] = 0;
        for (int j = 1; j <= m; j++) colcur[j] = 0;
        bool bad = false;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int v = grid[i][j];
                if (v != 0) {
                    if (v < 1 || v > 9 || rowused[i][v] || colused[j][v]) bad = true;
                    rowused[i][v] = true;
                    colused[j][v] = true;
                    rowcur[i] += v;
                    colcur[j] += v;
                } else {
                    empties.push_back({i, j});
                }
            }
        }
        cnt = 0;
        if (bad) {
            cout << "No answer.\n";
            continue;
        }
        dfs(0);
        if (cnt == 0) cout << "No answer.\n";
        else if (cnt > 1) cout << "Not unique.\n";
        else {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (j > 1) cout << " ";
                    cout << sol[i][j];
                }
                cout << "\n";
            }
        }
    }
    return 0;
}
