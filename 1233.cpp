#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> rem;
    for (int i = 1; i <= n; i++) rem.push_back(i);
    vector<long long> fact(n + 1, 1);
    for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;
    long long rank = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int v : rem)
            if (v < a[i]) cnt++;
        rank += (long long)cnt * fact[n - 1 - i];
        rem.erase(rem.begin() + cnt);
    }
    vector<int> b = a;
    next_permutation(b.begin(), b.end());
    cout << rank << "\n";
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << b[i];
    }
    cout << "\n";
    return 0;
}
