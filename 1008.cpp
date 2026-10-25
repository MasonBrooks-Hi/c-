#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cmath>
#include <numeric>
using namespace std;
int main() {
    int m;
    if (!(cin >> m)) return 0;
    vector<int> a(m);
    for (int i = 0; i < m; i++) cin >> a[i];
    for (int i = 1; i < m - 1; i++)
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) cout << a[i] << "\n";
    return 0;
}
