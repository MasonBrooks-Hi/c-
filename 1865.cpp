// 1865 聪明的小地鼠
// Mouse i takes multiples of i except i itself (mouse 1 takes only carrot 1).
// Surviving carrots = primes up to n. Separated by two spaces.
#include <cstdio>
#include <vector>
using namespace std;
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    vector<char> comp(n + 1, 0);
    for (int i = 2; (long long)i * i <= n; i++)
        if (!comp[i])
            for (int j = i * i; j <= n; j += i) comp[j] = 1;
    bool first = true;
    for (int i = 2; i <= n; i++) {
        if (!comp[i]) {
            printf("%s%d", first ? "" : "  ", i);
            first = false;
        }
    }
    printf("\n");
    return 0;
}
