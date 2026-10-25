#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    map<int, long long> c;
    for (int i = 0; i < n; i++) { cin >> a[i]; c[a[i]]++; }
    long long ans = 0;
    long long last = 0, mid = 0;
    for (auto it = c.begin(); it != c.end(); ++it) {
        int x = it->first;
        long long cnt = it->second;
        long long avail = cnt - mid - last;
        if (avail < 0) avail = 0;
        long long availNext = c[x + 1] - mid;
        if (availNext < 0) availNext = 0;
        long long t = avail;
        if (availNext < t) t = availNext;
        if (c[x + 2] < t) t = c[x + 2];
        ans += t;
        long long nlast = mid;
        long long nmid = t;
        last = nlast;
        mid = nmid;
    }
    cout << ans << "\n";
    return 0;
}
