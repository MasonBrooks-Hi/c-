#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    long long n, l, w;
    if (!(cin >> n >> l >> w)) return 0;
    long long leo = 0, mars = 0;
    for (long long i = 0; i < n; i++) {
        double v1, v2;
        cin >> v1 >> v2;
        // LEO 能在到达终点前（含恰好到达终点时）追上 MARS 则获胜
        // 追上时间 W/(V1-V2) <= 终点时间 L/V1
        bool leoWins = false;
        if (v1 > v2) {
            if (w * v1 <= l * (v1 - v2) + 1e-9) leoWins = true;
        }
        if (leoWins) leo++;
        else mars++;
    }
    printf("%lld\n%lld\n", leo, mars);
    cout << (leo > mars ? "LEO" : "MARS") << '\n';
    return 0;
}
