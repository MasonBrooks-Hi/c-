#include <iostream>
#include <algorithm>
using namespace std;

int g[1005][1005];

int main() {
    int n;
    if (!(cin >> n)) return 0;
    int w[105], total = 0;
    for (int i = 0; i < n; i++) { cin >> w[i]; total += w[i]; }
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= total; j++) g[i][j] = 0;
    g[0][0] = 1;
    for (int i = 0; i < n; i++)
        for (int k = n; k >= 1; k--)
            for (int s = total; s >= w[i]; s--)
                if (g[k - 1][s - w[i]]) g[k][s] = 1;
    int k = n / 2;
    int best = 0, bests = -1;
    for (int s = 0; s <= total; s++)
        if (g[k][s]) {
            int diff = total - 2 * s;
            if (diff < 0) diff = -diff;
            if (bests == -1 || diff < best) { best = diff; bests = s; }
        }
    int a = bests, b = total - bests;
    if (a > b) swap(a, b);
    cout << a << ' ' << b << '\n';
    return 0;
}
