#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Iv { int a, b; };
bool cmp(const Iv& x, const Iv& y) { return x.a < y.a; }

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<Iv> v(n);
    for (int i = 0; i < n; i++) cin >> v[i].a >> v[i].b;
    sort(v.begin(), v.end(), cmp);
    int l = v[0].a, r = v[0].b;
    bool ok = true;
    for (int i = 1; i < n; i++) {
        if (v[i].a <= r) r = max(r, v[i].b);
        else { ok = false; break; }
    }
    if (ok) cout << l << " " << r << "\n";
    else cout << "no\n";
    return 0;
}
