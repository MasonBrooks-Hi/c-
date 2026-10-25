// 1839 允许并列的排名
// Rank = 1 + number of scores strictly greater than the queried score.
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<int> s(n);
    for (auto &x : s) cin >> x;
    int m;
    cin >> m;
    int rank = 1;
    for (int x : s) if (x > m) rank++;
    printf("%d\n", rank);
    return 0;
}
