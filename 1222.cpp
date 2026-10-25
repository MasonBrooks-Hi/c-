#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> board;
int dx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};

bool solve(int x, int y, int step) {
    board[x][y] = step;
    if (step == n * n) return true;
    for (int d = 0; d < 8; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && board[nx][ny] == 0) {
            if (solve(nx, ny, step + 1)) return true;
        }
    }
    board[x][y] = 0;
    return false;
}

int main() {
    if (!(cin >> n)) return 0;
    board.assign(n + 1, vector<int>(n + 1, 0));
    solve(1, 1, 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j > 1) cout << " ";
            cout << board[i][j];
        }
        cout << "\n";
    }
    return 0;
}
