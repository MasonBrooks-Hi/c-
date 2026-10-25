#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cmath>
#include <numeric>
using namespace std;
int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    bool first = true;
    for (int x : a) if (x % 2 == 1) {
        if (first) { cout << x; first = false; }
        else cout << " " << x;
    }
    cout << "\n";
    for (int x : a) if (x % 2 == 0) cout << " " << x;
    cout << "\n";
    return 0;
}
