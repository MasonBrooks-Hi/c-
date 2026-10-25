#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    if (!(cin >> t)) return 0;
    int bestId = -1, bestScore = -1;
    for (int i = 0; i < t; i++) {
        int id, w, d, l;
        cin >> id >> w >> d >> l;
        int score = 3 * w + d - l;
        if (score > bestScore) { bestScore = score; bestId = id; }
    }
    cout << bestId << "\n";
    return 0;
}
