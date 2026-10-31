#include <iostream>
#include <algorithm>
using namespace std;

int dp[1005];

int main() {
    int N;
    if (!(cin >> N)) return 0;
    int t;
    cin >> t;
    for (int i = 0; i < N; i++) {
        int f, ti;
        cin >> f >> ti;
        for (int j = t; j >= ti; j--)
            dp[j] = max(dp[j], dp[j - ti] + f);
    }
    cout << dp[t] << '\n';
    return 0;
}
