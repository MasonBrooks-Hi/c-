#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    vector<int> a(10);
    for (int i = 0; i < 10; ++i) cin >> a[i];
    vector<int> odd, even;
    for (int x : a) {
        if (x % 2 != 0) odd.push_back(x);
        else even.push_back(x);
    }
    sort(odd.begin(), odd.end(), greater<int>());
    sort(even.begin(), even.end());
    bool first = true;
    for (int x : odd) { if (!first) cout << " "; cout << x; first = false; }
    for (int x : even) { if (!first) cout << " "; cout << x; first = false; }
    cout << endl;
    return 0;
}
