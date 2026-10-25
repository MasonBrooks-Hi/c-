#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    if (!(cin >> n >> k)) return 0;
    vector<vector<long long>> s(n + 1, vector<long long>(k + 1, 0));
    s[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++)
            s[i][j] = s[i - 1][j - 1] + (long long)j * s[i - 1][j];
    cout << s[n][k] << "\n";
    return 0;
}
