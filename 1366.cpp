#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

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
    sort(solutions.begin(), solutions.end());
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int b;
        cin >> b;
        cout << solutions[b - 1] << "\n";
    }
    return 0;
}
