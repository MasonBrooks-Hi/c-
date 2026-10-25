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
    int cnt = 0;
    for (int x : a) if (x == k) cnt++;
    cout << cnt << "\n";
    return 0;
}
