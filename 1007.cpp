#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cmath>
#include <numeric>
using namespace std;
int main() {
    int n, k;
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> k;
    int pos = -1;
    for (int i = 0; i < n; i++)
        if (a[i] == k) { pos = i + 1; break; }
    cout << pos << "\n";
    return 0;
}
