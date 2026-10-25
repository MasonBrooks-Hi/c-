#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, k, ans;
vector<string> board;
bool col_used[8];

void dfs(int row, int placed) {
    if (placed == k) { ans++; return; }
    if (row == n) return;
    // option: place a piece on this row (at some unused column that is '#')
    for (int c = 0; c < n; c++) {
        if (board[row][c] == '#' && !col_used[c]) {
            col_used[c] = true;
            dfs(row + 1, placed + 1);
            col_used[c] = false;
        }
    }
    // option: skip this row
    dfs(row + 1, placed);
}

int main() {
    while (cin >> n >> k) {
        if (n == -1 && k == -1) break;
        board.resize(n);
        for (int i = 0; i < n; i++) cin >> board[i];
        ans = 0;
        for (int i = 0; i < 8; i++) col_used[i] = false;
        dfs(0, 0);
        cout << ans << "\n";
    }
    return 0;
}
