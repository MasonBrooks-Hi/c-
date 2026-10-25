// 1871 看电影
// Reverse the list of student IDs.
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<long long> v(n);
    for (auto &x : v) cin >> x;
    for (int i = n - 1; i >= 0; i--) printf("%s%lld", i == n - 1 ? "" : " ", v[i]);
    printf("\n");
    return 0;
}
