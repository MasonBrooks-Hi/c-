#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<long long> a(n);
    map<long long, int> cnt;
    for (int i = 0; i < n; i++) { cin >> a[i]; cnt[a[i]]++; }
    long long m;
    cin >> m;
    sort(a.begin(), a.end());
    bool found = false;
    for (int i = 0; i < n; i++) {
        long long v = a[i];
        long long need = m - v;
        if (need == v) {
            if (cnt[v] >= 2) {
                cout << v << " " << need << "\n";
                found = true;
                break;
            }
        } else if (cnt.count(need)) {
            if (v < need) cout << v << " " << need << "\n";
            else cout << need << " " << v << "\n";
            found = true;
            break;
        }
    }
    if (!found) cout << "No\n";
    return 0;
}
