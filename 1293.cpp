#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    if (cin >> n) {
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        int cnt[100] = {0};
        for (int x : a) cnt[x + 50]++;
        int ans = -1;
        for (int i = 0; i < 100; ++i) if (cnt[i] > n / 2) { ans = i - 50; break; }
        if (ans == -1) cout << "no" << endl;
        else cout << ans << endl;
    }
    return 0;
}
