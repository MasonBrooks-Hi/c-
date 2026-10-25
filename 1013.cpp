#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    int n;
    if (!(cin >> n)) return 0;
    long long s = 0, x;
    for (int i = 0; i < n; i++) { cin >> x; s += x; }
    printf("%lld %.5f\n", s, (double)s / n);
    return 0;
}
