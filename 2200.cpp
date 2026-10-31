#include <iostream>
#include <vector>
using namespace std;

struct Carpet {
    int a, b, g, k;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    if (!(cin >> n)) return 0;
    vector<Carpet> c(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> c[i].a >> c[i].b >> c[i].g >> c[i].k;
    }
    int x, y;
    cin >> x >> y;
    int ans = -1;
    for (int i = 1; i <= n; i++) {
        if (x >= c[i].a && x <= c[i].a + c[i].g &&
            y >= c[i].b && y <= c[i].b + c[i].k) {
            ans = i;
        }
    }
    cout << ans << "\n";
    return 0;
}
