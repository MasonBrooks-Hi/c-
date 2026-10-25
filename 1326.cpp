#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    int n, k;
    if (cin >> n >> k) {
        vector<pair<long long, string>> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i].first >> v[i].second;
        sort(v.begin(), v.end(), [](const pair<long long, string>& a, const pair<long long, string>& b) {
            if (a.second != b.second) return a.second > b.second;
            return a.first < b.first;
        });
        cout << v[k - 1].first << " " << v[k - 1].second << "\n";
    }
    return 0;
}
