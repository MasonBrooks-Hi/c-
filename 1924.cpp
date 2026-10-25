#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int m, s, c;
    if (!(cin >> m >> s >> c)) return 0;
    vector<int> a(c);
    for (int i = 0; i < c; i++) cin >> a[i];
    sort(a.begin(), a.end());
    // 用至多 M 块木板覆盖所有牛：总跨度减去最大的 M-1 个空隙
    long long total = (long long)a[c - 1] - a[0] + 1;
    vector<int> gaps;
    for (int i = 1; i < c; i++) gaps.push_back(a[i] - a[i - 1] - 1);
    sort(gaps.rbegin(), gaps.rend());
    for (int i = 0; i < m - 1 && i < (int)gaps.size(); i++) total -= gaps[i];
    cout << total << '\n';
    return 0;
}
