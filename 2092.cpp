#include <iostream>
using namespace std;

const int N = 1000005;
long long v[N];
int lch[N], rch[N];
int sz[N];

bool mirror(int a, int b) {
    if (a == -1 && b == -1) return true;
    if (a == -1 || b == -1) return false;
    if (v[a] != v[b]) return false;
    return mirror(lch[a], rch[b]) && mirror(rch[a], lch[b]);
}

int getsz(int u) {
    if (u == -1) return 0;
    sz[u] = 1 + getsz(lch[u]) + getsz(rch[u]);
    return sz[u];
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) cin >> lch[i] >> rch[i];
    getsz(1);
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        if (mirror(lch[i], rch[i])) {
            if (sz[i] > ans) ans = sz[i];
        }
    }
    cout << ans << '\n';
    return 0;
}
