#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    long long p;
    if (!(cin >> n >> p)) return 0;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<long long> feat(n + 1);
    long long ending = 0, best = 0;
    for (int i = 1; i <= n; i++) {
        ending = max(a[i], ending + a[i]);
        best = max(best, ending);
        feat[i] = best;
    }
    vector<long long> score(n + 1);
    long long mx = feat[1];
    score[1] = feat[1];
    long long run = score[1] + feat[1];
    for (int i = 2; i <= n; i++) {
        score[i] = run;
        run = max(run, score[i] + feat[i]);
        mx = max(mx, score[i]);
    }
    mx = max(mx, score[1]);
    if (mx >= 0) cout << (mx % p) << "\n";
    else cout << "-" << ((-mx) % p) << "\n";
    return 0;
}
