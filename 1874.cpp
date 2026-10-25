// 1874 亲密数对
// Here "因子和" excludes 1 and the number itself.
// sd(i) = sum of divisors d with 1 < d < i. Pair (a,b): sd(a)=b, sd(b)=a, a!=b.
#include <cstdio>
#include <vector>
using namespace std;
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    vector<int> sd(n + 1, 0);
    for (int i = 2; i <= n; i++)
        for (int j = 2 * i; j <= n; j += i)
            sd[j] += i;
    for (int a = 2; a <= n; a++) {
        int b = sd[a];
        if (b != a && b >= 2 && b <= n && sd[b] == a)
            printf("%d %d\n", a, b);
    }
    return 0;
}
