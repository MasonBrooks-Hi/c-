#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int k;
    cin >> k;
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < k; i++) cout << a[i] << "\n";
    return 0;
}
