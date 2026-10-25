// 1880 图书馆
// Find closest book id below K and above K, sum them, check primality of the sum.
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, k;
    if (!(cin >> n >> k)) return 0;
    int below = -1, above = -1;
    for (int i = 0; i < n; i++) {
        int id;
        cin >> id;
        if (id < k && (below == -1 || id > below)) below = id;
        if (id > k && (above == -1 || id < above)) above = id;
    }
    int sum = (below == -1 ? 0 : below) + (above == -1 ? 0 : above);
    bool prime = sum >= 2;
    for (long long d = 2; d * d <= sum; d++)
        if (sum % d == 0) { prime = false; break; }
    printf("%d\n%c\n", sum, prime ? 'Y' : 'F');
    return 0;
}
