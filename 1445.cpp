#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, i, j;
    if (!(cin >> N >> i >> j)) return 0;
    // same row
    for (int c = 1; c <= N; c++) {
        if (c > 1) cout << " ";
        cout << "(" << i << "," << c << ")";
    }
    cout << "\n";
    // same column
    for (int r = 1; r <= N; r++) {
        if (r > 1) cout << " ";
        cout << "(" << r << "," << j << ")";
    }
    cout << "\n";
    // main diagonal (row - col = i - j)
    for (int r = 1; r <= N; r++) {
        int c = r - (i - j);
        if (c >= 1 && c <= N) {
            if (r > 1) cout << " ";
            cout << "(" << r << "," << c << ")";
        }
    }
    cout << "\n";
    // anti diagonal (row + col = i + j)
    for (int r = N; r >= 1; r--) {
        int c = (i + j) - r;
        if (c >= 1 && c <= N) {
            if (r < N) cout << " ";
            cout << "(" << r << "," << c << ")";
        }
    }
    cout << "\n";
    return 0;
}
