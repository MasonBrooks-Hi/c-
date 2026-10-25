#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    int n;
    if (cin >> n) {
        vector<pair<int, string>> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i].second >> v[i].first;
        sort(v.begin(), v.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
            if (a.first != b.first) return a.first > b.first;
            return a.second < b.second;
        });
        for (auto& p : v) cout << p.second << " " << p.first << "\n";
    }
    return 0;
}
