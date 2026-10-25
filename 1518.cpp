#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Act { int s, e; };
bool cmp(const Act& a, const Act& b) { return a.e < b.e; }

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<Act> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].s >> a[i].e;
    sort(a.begin(), a.end(), cmp);
    int cnt = 0, last = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].s >= last) { cnt++; last = a[i].e; }
    }
    cout << cnt << "\n";
    return 0;
}
