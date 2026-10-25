#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    // 生成 n 阶回形矩阵，左上角为 1，顺时针向内盘旋
    vector<vector<int>> g(n, vector<int>(n, 0));
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    int val = 1;
    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++) g[top][j] = val++;
        top++;
        for (int i = top; i <= bottom; i++) g[i][right] = val++;
        right--;
        if (top <= bottom) {
            for (int j = right; j >= left; j--) g[bottom][j] = val++;
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--) g[i][left] = val++;
            left++;
        }
    }
    // 路径格子数 = 2n-1，最大和的上界
    int maxSum = (2 * n - 1) * n * n + 1;
    // dp[i][j][s] = 到达 (i,j) 且和为 s 的路径数
    vector<vector<vector<long long>>> dp(
        n, vector<vector<long long>>(n, vector<long long>(maxSum, 0)));
    dp[0][0][g[0][0]] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) continue;
            for (int s = 0; s < maxSum; s++) {
                long long ways = 0;
                if (i > 0 && s >= g[i][j]) ways += dp[i - 1][j][s - g[i][j]];
                if (j > 0 && s >= g[i][j]) ways += dp[i][j - 1][s - g[i][j]];
                dp[i][j][s] = ways;
            }
        }
    }
    // 素数筛
    vector<bool> comp(maxSum, false);
    for (int i = 2; (long long)i * i < maxSum; i++)
        if (!comp[i])
            for (int j = i * i; j < maxSum; j += i) comp[j] = true;
    long long ans = 0;
    for (int s = 2; s < maxSum; s++)
        if (!comp[s]) ans += dp[n - 1][n - 1][s];
    cout << ans << '\n';
    return 0;
}
