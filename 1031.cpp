#include <iostream>
using namespace std;
int main() {
    int money = 0, dep = 0;
    for (int m = 1; m <= 12; m++) {
        int b;
        if (!(cin >> b)) return 0;
        money += 300;
        if (money < b) { cout << -m << "\n"; return 0; }
        money -= b;
        if (money >= 100) {
            int d = (money / 100) * 100;
            dep += d;
            money -= d;
        }
    }
    cout << money + dep * 6 / 5 << "\n";
    return 0;
}
