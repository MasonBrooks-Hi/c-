#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> a;
    int x;
    while (cin >> x) a.push_back(x);
    int n = (int)a.size();
    vector<int> dp1(n, 1), dp2(n, 1);
    int m1 = 0, m2 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] >= a[i]) dp1[i] = max(dp1[i], dp1[j] + 1);
            if (a[j] < a[i]) dp2[i] = max(dp2[i], dp2[j] + 1);
        }
        m1 = max(m1, dp1[i]);
        m2 = max(m2, dp2[i]);
    }
    cout << m1 << "\n" << m2 << "\n";
    return 0;
}
