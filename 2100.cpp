#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

const int N = 105;
int a[N], sum[N];
int dpmin[N][N], dpmax[N][N];

int main() {
    int n;
    if (!(cin >> n)) return 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++) { dpmin[i][i] = 0; dpmax[i][i] = 0; }
    for (int len = 2; len <= n; len++)
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            dpmin[i][j] = INT_MAX;
            dpmax[i][j] = 0;
            int cost = sum[j] - sum[i - 1];
            for (int k = i; k < j; k++) {
                dpmin[i][j] = min(dpmin[i][j], dpmin[i][k] + dpmin[k + 1][j] + cost);
                dpmax[i][j] = max(dpmax[i][j], dpmax[i][k] + dpmax[k + 1][j] + cost);
            }
        }
    cout << dpmin[1][n] << '\n' << dpmax[1][n] << '\n';
    return 0;
}
