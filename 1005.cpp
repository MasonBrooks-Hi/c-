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
    int mx = -200;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > mx) mx = a[i];
    }
    for (int i = 0; i < n; i++)
        if (a[i] == mx) cout << i + 1 << "\n";
    return 0;
}
