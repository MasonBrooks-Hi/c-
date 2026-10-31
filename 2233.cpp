#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int K;
    if (!(cin >> K)) return 0;
    const int MAXN = 20000;
    vector<int> dcount(MAXN + 1, 0);
    for (int i = 1; i <= MAXN; i++)
        for (int j = i; j <= MAXN; j += i) dcount[j]++;
    int ans = -1;
    for (int n = 1; n <= MAXN; n++) {
        if (dcount[n] == K) { ans = n; break; }
    }
    if (ans == -1) {
        cout << "NO SOLUTION\n";
        return 0;
    }
    cout << ans << "\n";
    vector<int> divs;
    for (int i = 1; i * i <= ans; i++) {
        if (ans % i == 0) {
            divs.push_back(i);
            if (i * i != ans) divs.push_back(ans / i);
        }
    }
    sort(divs.begin(), divs.end());
    for (size_t i = 0; i < divs.size(); i++) {
        if (i) cout << " ";
        cout << divs[i];
    }
    cout << "\n";
    return 0;
}
