// 1872 小明排队做操迟到
// Insert y right after x in the list.
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    long long x, y;
    if (!(cin >> n >> x >> y)) return 0;
    vector<long long> v(n);
    for (auto &z : v) cin >> z;
    size_t pos = v.size();
    for (size_t i = 0; i < v.size(); i++)
        if (v[i] == x) { pos = i + 1; break; }
    v.insert(v.begin() + pos, y);
    for (size_t i = 0; i < v.size(); i++) printf("%s%lld", i ? " " : "", v[i]);
    printf("\n");
    return 0;
}
