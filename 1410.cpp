#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    if (!(cin >> n)) return 0;
    vector<long long> R(n), G(n), B(n);
    for (int i = 0; i < n; i++) cin >> R[i];
    for (int i = 0; i < n; i++) cin >> G[i];
    for (int i = 0; i < n; i++) cin >> B[i];
    long long r = R[0], g = G[0], b = B[0];
    for (int i = 1; i < n; i++) {
        long long nr = R[i] + min(g, b);
        long long ng = G[i] + min(r, b);
        long long nb = B[i] + min(r, g);
        r = nr; g = ng; b = nb;
    }
    cout << min({r, g, b}) << "\n";
    return 0;
}
