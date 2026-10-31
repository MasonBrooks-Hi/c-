#include <iostream>
#include <vector>
using namespace std;

short memo[105][100005];

int w[105];
int N, target;

long long cnt(int i, int rem) {
    if (rem == 0) return 1;
    if (i == N) return 0;
    if (memo[i][rem] != -1) return memo[i][rem];
    long long r = 0;
    if (rem >= w[i]) r = cnt(i + 1, rem - w[i]);
    r += cnt(i + 1, rem);
    if (r > 2) r = 2;
    return memo[i][rem] = (short)r;
}

int main() {
    int TotalW;
    if (!(cin >> TotalW)) return 0;
    cin >> N;
    int total = 0;
    for (int i = 0; i < N; i++) { cin >> w[i]; total += w[i]; }
    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= target; j++) memo[i][j] = -1;
    target = total - TotalW;
    if (target < 0) { cout << 0 << '\n'; return 0; }
    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= target; j++) memo[i][j] = -1;
    long long ways = cnt(0, target);
    if (ways == 0) { cout << 0 << '\n'; return 0; }
    if (ways >= 2) { cout << -1 << '\n'; return 0; }
    vector<int> ans;
    int rem = target;
    for (int i = 0; i < N; i++) {
        if (rem >= w[i] && cnt(i + 1, rem - w[i]) > 0) {
            ans.push_back(i + 1);
            rem -= w[i];
        }
    }
    for (size_t i = 0; i < ans.size(); i++) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << '\n';
    return 0;
}
