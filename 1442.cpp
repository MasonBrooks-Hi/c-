#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    bool seen[100] = {false};
    bool first = true;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (!seen[a[i]]) {
            seen[a[i]] = true;
            if (!first) cout << " ";
            cout << a[i];
            first = false;
        }
    }
    cout << "\n";
    return 0;
}
