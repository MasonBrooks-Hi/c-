// 1832 最小公倍数
#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    long long m, n;
    if (scanf("%lld %lld", &m, &n) != 2) return 0;
    long long a = m < 0 ? -m : m, b = n < 0 ? -n : n;
    while (b) { long long t = a % b; a = b; b = t; }
    long long g = a;
    printf("%lld\n", m / g * n);
    return 0;
}
