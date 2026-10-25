#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    if (cin >> n) {
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        vector<int> odds;
        for (int x : a) if (x % 2 != 0) odds.push_back(x);
        sort(odds.begin(), odds.end());
        for (size_t i = 0; i < odds.size(); ++i) {
            if (i) cout << ",";
            cout << odds[i];
        }
        cout << endl;
    }
    return 0;
}
