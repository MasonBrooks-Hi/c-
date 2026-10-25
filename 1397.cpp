#include <iostream>
#include <string>
using namespace std;

long long N, ans;
string s = "123456789";

void dfs(int idx, long long cur, long long prev) {
    if (idx == 9) {
        if (cur + prev == N) ans++;
        return;
    }
    long long d = s[idx] - '0';
    // concatenate with current term
    long long newPrev = (prev >= 0) ? prev * 10 + d : prev * 10 - d;
    dfs(idx + 1, cur, newPrev);
    // new term with +
    dfs(idx + 1, cur + prev, d);
    // new term with -
    dfs(idx + 1, cur + prev, -d);
}

int main() {
    if (!(cin >> N)) return 0;
    ans = 0;
    dfs(1, 0, 1); // first digit '1' as first term
    cout << ans << "\n";
    return 0;
}
