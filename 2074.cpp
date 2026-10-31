#include <iostream>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    long long odd = 0, even = 0;
    for (int i = 1; i <= 2 * n; i++) {
        long long x;
        cin >> x;
        if (i % 2 == 1) odd += x;
        else even += x;
    }
    long long mx = (odd > even) ? odd : even;
    cout << "Y " << mx << '\n';
    return 0;
}
