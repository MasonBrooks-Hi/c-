#include <iostream>
using namespace std;

long long countBeautiful(long long x) {
    return x / 3 + x / 5 - x / 15;
}

int main() {
    int M;
    if (!(cin >> M)) return 0;
    while (M--) {
        long long N;
        cin >> N;
        long long lo = 1, hi = 2000000, ans = 0;
        while (lo <= hi) {
            long long mid = (lo + hi) / 2;
            if (countBeautiful(mid) >= N) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
