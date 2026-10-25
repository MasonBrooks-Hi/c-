#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    string s;
    cin >> s;
    int n = (int)s.size();
    vector<tuple<int, int, string>> v;
    for (int i = 0; i < n; i++) {
        for (int L = 2; i + L - 1 < n; L++) {
            string sub = s.substr(i, L);
            string r = sub;
            reverse(r.begin(), r.end());
            if (sub == r) v.push_back({L, i, sub});
        }
    }
    sort(v.begin(), v.end(), [](const auto &a, const auto &b) {
        if (get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b);
        return get<1>(a) < get<1>(b);
    });
    for (auto &x : v) cout << get<2>(x) << "\n";
    return 0;
}
