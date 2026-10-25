#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int best = -1, bestDay = 0;
    for (int day = 1; day <= 7; day++) {
        int a, b;
        cin >> a >> b;
        int total = a + b;
        if (total > 8) {
            if (total > best) { best = total; bestDay = day; }
        }
    }
    if (bestDay == 0) cout << "0\n";
    else cout << bestDay << "\n";
    return 0;
}
