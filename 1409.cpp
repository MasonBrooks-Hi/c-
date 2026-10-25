#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    if (!(cin >> n)) return 0;
    vector<pair<int, int>> ev;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        ev.push_back({a, 1});
        ev.push_back({b + 1, -1});
    }
    sort(ev.begin(), ev.end());
    int cur = 0, mx = 0;
    for (size_t i = 0; i < ev.size(); i++) {
        cur += ev[i].second;
        if (cur > mx) mx = cur;
    }
    cout << mx << "\n";
    return 0;
}
