#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int x;
    if (!(cin >> x)) return 0;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int cnt = 0;
    int cur = 0; // 岸边位置
    for (int i = 0; i < n; i++) {
        if (a[i] - cur <= x) {
            cnt++;
            cur = a[i];
        }
    }
    cout << cnt << '\n';
    return 0;
}
