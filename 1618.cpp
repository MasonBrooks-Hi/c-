// 1618 友好城市
// 思路：每条航道连接南岸 a 与北岸 b。两条航道相交当且仅当它们的端点顺序相反。
// 按南岸坐标 a 升序排序后，所选航道必须使北岸坐标 b 严格递增，
// 因此答案就是 b 序列的最长严格上升子序列长度（LIS）。
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    sort(p.begin(), p.end());

    vector<int> tails;               // tails[k] = 长度为 k+1 的上升子序列最小结尾
    for (size_t i = 0; i < p.size(); i++) {
        int b = p[i].second;
        auto it = lower_bound(tails.begin(), tails.end(), b);
        if (it == tails.end()) tails.push_back(b);
        else *it = b;
    }
    cout << tails.size() << "\n";
    return 0;
}
