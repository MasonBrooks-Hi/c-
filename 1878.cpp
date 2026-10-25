// 1878 排队做操迟到II
// Insert m students, each right after a given existing student.
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<long long> v(n);
    for (auto &z : v) cin >> z;
    for (int k = 0; k < m; k++) {
        long long x, y;
        cin >> x >> y;
        size_t pos = v.size();
        for (size_t i = 0; i < v.size(); i++)
            if (v[i] == x) { pos = i + 1; break; }
        v.insert(v.begin() + pos, y);
    }
    for (size_t i = 0; i < v.size(); i++) printf("%s%lld", i ? " " : "", v[i]);
    printf("\n");
    return 0;
}
