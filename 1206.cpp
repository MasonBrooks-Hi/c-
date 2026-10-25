#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> res;
    for (int r = 0; r < 1000; r++) {
        long long v = (long long)r * r * r;
        if (v % 1000 == 111) res.push_back(r);
    }
    sort(res.begin(), res.end());
    int n;
    cin >> n;
    while (n--) {
        long long m;
        cin >> m;
        long long lo = 0, hi = 200000000000000LL;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            long long cnt = 0;
            for (int r : res)
                if (mid >= r) cnt += (mid - r) / 1000 + 1;
            if (cnt >= m) hi = mid;
            else lo = mid + 1;
        }
        cout << lo << endl;
    }
    return 0;
}
