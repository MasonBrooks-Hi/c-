#include <iostream>
using namespace std;

int count_factors(int n, int minf) {
    int ans = 1; // n itself as a single factor (if n>=minf)
    for (int i = minf; (long long)i * i <= n; i++) {
        if (n % i == 0) ans += count_factors(n / i, i);
    }
    return ans;
}

int main() {
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int a;
        cin >> a;
        cout << count_factors(a, 2) << "\n";
    }
    return 0;
}
