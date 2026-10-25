#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    int N, K;
    if (!(cin >> N >> K)) return 0;
    vector<int> len(N);
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        double x;
        cin >> x;
        len[i] = (int)(x * 100 + 0.5);
        sum += len[i];
    }
    int lo = 1, hi = (int)sum, ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        long long cnt = 0;
        for (int i = 0; i < N; i++) cnt += len[i] / mid;
        if (cnt >= K) { ans = mid; lo = mid + 1; }
        else hi = mid - 1;
    }
    if (ans == 0) cout << "0.00\n";
    else cout << fixed << setprecision(2) << (ans / 100.0) << "\n";
    return 0;
}
