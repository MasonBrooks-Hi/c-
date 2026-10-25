#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int M, W, k;
    if (!(cin >> M >> W >> k)) return 0;
    for (int t = 1; t <= k; t++) {
        int man = (t - 1) % M + 1;
        int woman = (t - 1) % W + 1;
        cout << man << " " << woman << "\n";
    }
    return 0;
}
