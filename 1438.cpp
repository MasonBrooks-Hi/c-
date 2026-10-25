#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int M;
    if (!(cin >> M)) return 0;
    vector<int> a(M);
    int mn = 2000000000, mx = -2000000000;
    for (int i = 0; i < M; i++) {
        cin >> a[i];
        if (a[i] < mn) mn = a[i];
        if (a[i] > mx) mx = a[i];
    }
    cout << mx - mn << "\n";
    return 0;
}
