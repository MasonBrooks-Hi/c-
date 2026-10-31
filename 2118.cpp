#include <iostream>
#include <algorithm>
using namespace std;

int grid[1005][1005];

int main() {
    int n;
    if (!(cin >> n)) return 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> grid[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            grid[i][j] += max(grid[i - 1][j], grid[i][j - 1]);
    cout << grid[n][n] << '\n';
    return 0;
}
