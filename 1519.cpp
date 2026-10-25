#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Iv { int a, b; };
bool cmp(const Iv& x, const Iv& y) { return x.b < y.b; }

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<Iv> v(n);
    for (int i = 0; i < n; i++) cin >> v[i].a >> v[i].b;
    sort(v.begin(), v.end(), cmp);
    int last = -1, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (v[i].a > last) { cnt++; last = v[i].b; }
    }
    cout << cnt << "\n";
    return 0;
}
