#include <iostream>
using namespace std;

int main() {
    int x;
    if (!(cin >> x)) return 0;
    int bestA = -1, bestB = -1, bestC = -1, bestCount = -1;
    for (int a = 0; a * 6 <= x; a++) {
        for (int b = 0; a * 6 + b * 5 <= x; b++) {
            int rem = x - a * 6 - b * 5;
            if (rem % 4 == 0) {
                int c = rem / 4;
                int cnt = a + b + c;
                if (cnt > bestCount || (cnt == bestCount && c > bestC)) {
                    bestCount = cnt;
                    bestC = c;
                    bestB = b;
                    bestA = a;
                }
            }
        }
    }
    cout << bestA << " " << bestB << " " << bestC << "\n";
    return 0;
}
