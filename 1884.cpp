// 1884 Hanoi双塔问题
// 2n disks (n identical pairs). Minimal moves: A(n) = 2*A(n-1) + 2, A(1) = 2 -> 2^(n+1) - 2.
// n up to 200 -> big integer.
#include <cstdio>
#include <vector>
using namespace std;
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int e = n + 1; // compute 2^e
    vector<int> d;
    d.push_back(1); // little-endian decimal digits
    for (int i = 0; i < e; i++) {
        int carry = 0;
        for (auto &x : d) {
            x = x * 2 + carry;
            carry = x / 10;
            x %= 10;
        }
        if (carry) d.push_back(carry);
    }
    // subtract 2
    int i = 0, sub = 2;
    while (sub) {
        if (i >= (int)d.size()) d.push_back(0);
        if (d[i] >= sub) { d[i] -= sub; sub = 0; }
        else { d[i] += 10 - sub; sub = 1; }
        i++;
    }
    while (d.size() > 1 && d.back() == 0) d.pop_back();
    for (int j = (int)d.size() - 1; j >= 0; j--) printf("%d", d[j]);
    printf("\n");
    return 0;
}
