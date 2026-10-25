#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Output all 92 solutions of the 8-queens problem in the format shown.
int cols[8];
vector<string> solutions;

bool ok(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (cols[i] == col) return false;
        if (abs(cols[i] - col) == row - i) return false;
    }
    return true;
}

void dfs(int row) {
    if (row == 8) {
        string s;
        for (int i = 0; i < 8; i++) s += char('0' + cols[i] + 1);
        solutions.push_back(s);
        return;
    }
    for (int c = 0; c < 8; c++) {
        if (ok(row, c)) {
            cols[row] = c;
            dfs(row + 1);
        }
    }
}

int main() {
    dfs(0);
    // sort by integer value of queen strings
    sort(solutions.begin(), solutions.end());
    for (size_t idx = 0; idx < solutions.size(); idx++) {
        cout << " NO." << (idx + 1) << " \n";
        string s = solutions[idx];
        for (int r = 0; r < 8; r++) {
            int c = s[r] - '0' - 1;
            for (int col = 0; col < 8; col++)
                cout << (col == c ? 1 : 0) << (col == 7 ? "" : " ");
            cout << "\n";
        }
    }
    return 0;
}
