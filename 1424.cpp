#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long red, y, g, br, bl, p, bk;
    if (!(cin >> red >> y >> g >> br >> bl >> p >> bk)) return 0;
    long long best = 0;
    if (y > 0) best = 2;
    if (g > 0 && best < 3) best = 3;
    if (br > 0 && best < 4) best = 4;
    if (bl > 0 && best < 5) best = 5;
    if (p > 0 && best < 6) best = 6;
    if (bk > 0 && best < 7) best = 7;
    long long finalsum = y * 2 + g * 3 + br * 4 + bl * 5 + p * 6 + bk * 7;
    long long score = finalsum;
    if (red > 0) {
        if (best > 0) score += red * (1 + best);
        else score += red;
    }
    cout << score << "\n";
    return 0;
}
