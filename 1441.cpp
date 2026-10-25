#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    int fmax = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > fmax) fmax = a[i];
    }
    vector<int> cnt(fmax + 1, 0);
    for (int i = 0; i < n; i++) cnt[a[i]]++;
    for (int i = 0; i <= fmax; i++) cout << cnt[i] << "\n";
    return 0;
}
