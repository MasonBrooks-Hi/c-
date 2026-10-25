#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int x;
    cin >> x;
    int pos = -1;
    for (int i = 0; i < n; i++)
        if (a[i] == x) { pos = i + 1; break; }
    cout << pos << "\n";
    return 0;
}
