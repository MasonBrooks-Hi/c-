#include <iostream>
#include <vector>
using namespace std;

int main() {
    int K;
    while (cin >> K && K != 0) {
        vector<int> a(K);
        for (int i = 0; i < K; i++) cin >> a[i];
        int maxsum = -2000000000;
        int cur = 0, curstart = 0, beststart = 0, bestend = 0;
        for (int i = 0; i < K; i++) {
            if (cur <= 0) { cur = a[i]; curstart = i; }
            else cur += a[i];
            if (cur > maxsum || (cur == maxsum && (curstart < beststart ||
                (curstart == beststart && i < bestend)))) {
                maxsum = cur;
                beststart = curstart;
                bestend = i;
            }
        }
        if (maxsum < 0) cout << 0 << ' ' << a[0] << ' ' << a[K - 1] << '\n';
        else cout << maxsum << ' ' << a[beststart] << ' ' << a[bestend] << '\n';
    }
    return 0;
}
