#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<pair<double, int>> v(n); // (time, index)
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i + 1;
    }
    // 短作业优先可使平均等待时间最小；同长度保持原编号顺序
    stable_sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        cout << v[i].second;
        if (i + 1 < n) cout << ' ';
    }
    cout << '\n';
    return 0;
}
