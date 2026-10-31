#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    if (!(cin >> n)) return 0;
    for (int cas = 1; cas <= n; cas++) {
        string a, b, c;
        cin >> a >> b >> c;
        int na = a.length(), nb = b.length(), nc = c.length();
        vector<vector<bool>> dp(na + 1, vector<bool>(nb + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= na; i++) {
            for (int j = 0; j <= nb; j++) {
                if (!dp[i][j]) continue;
                int k = i + j;
                if (i < na && k < nc && a[i] == c[k]) dp[i + 1][j] = true;
                if (j < nb && k < nc && b[j] == c[k]) dp[i][j + 1] = true;
            }
        }
        cout << "Case " << cas << ": " << (dp[na][nb] ? "yes" : "no") << "\n";
    }
    return 0;
}
