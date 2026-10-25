#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    if (!(cin >> n)) return 0;
    int minx = 2000000000, maxx = -2000000000;
    int miny = 2000000000, maxy = -2000000000;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a < minx) minx = a;
        if (a > maxx) maxx = a;
        if (b < miny) miny = b;
        if (b > maxy) maxy = b;
    }
    long long dx = maxx - minx;
    long long dy = maxy - miny;
    long long side = max(dx, dy);
    cout << side * side << "\n";
    return 0;
}
