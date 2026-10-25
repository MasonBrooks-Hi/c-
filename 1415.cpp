#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Req {
    int t, from, to;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x, n;
    if (!(cin >> x >> n)) return 0;
    vector<Req> reqs(n);
    for (int i = 0; i < n; i++) cin >> reqs[i].t >> reqs[i].from >> reqs[i].to;
    stable_sort(reqs.begin(), reqs.end(), [](const Req& a, const Req& b) { return a.t < b.t; });

    long long total = 0;
    long long currentTime = reqs[0].t;
    int cur = x;
    for (auto& r : reqs) {
        if (r.t > currentTime) {
            total += (r.t - currentTime);
            currentTime = r.t;
        }
        int d1 = abs(cur - r.from);
        total += 3LL * d1;
        if (d1 > 0) total += 6;
        int d2 = abs(r.from - r.to);
        total += 3LL * d2;
        total += 6;
        currentTime += 3LL * d1 + (d1 > 0 ? 6 : 0) + 3LL * d2 + 6;
        cur = r.to;
    }
    cout << total << "\n";
    return 0;
}
