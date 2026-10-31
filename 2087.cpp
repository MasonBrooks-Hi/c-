#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct St {
    double d, p;
};

bool cmp(St a, St b) { return a.d < b.d; }

int main() {
    double D1, C, D2, P;
    int n;
    if (!(cin >> D1 >> C >> D2 >> P >> n)) return 0;
    vector<St> st(n + 2);
    st[0] = {0, P};
    for (int i = 1; i <= n; i++) cin >> st[i].d >> st[i].p;
    st[n + 1] = {D1, 0};   // destination, treated as cheapest
    n = n + 1;
    sort(st.begin(), st.begin() + n + 1, cmp);

    double maxr = C * D2;
    for (int i = 0; i < n; i++) {
        if (st[i + 1].d - st[i].d > maxr + 1e-9) {
            cout << "No Solution" << '\n';
            return 0;
        }
    }

    double cost = 0, gas = 0;
    int i = 0;
    while (i < n) {
        int j = -1;
        for (int k = i + 1; k <= n; k++) {
            if (st[k].d - st[i].d > maxr + 1e-9) break;
            if (st[k].p < st[i].p - 1e-9) { j = k; break; }
        }
        if (j != -1) {
            double need = (st[j].d - st[i].d) / D2;
            if (gas < need - 1e-9) {
                cost += (need - gas) * st[i].p;
                gas = need;
            }
            gas -= need;
            i = j;
        } else {
            int k = -1;
            double minp = 1e18;
            for (int t = i + 1; t <= n; t++) {
                if (st[t].d - st[i].d > maxr + 1e-9) break;
                if (st[t].p < minp - 1e-9) { minp = st[t].p; k = t; }
            }
            if (k == -1) break;
            cost += (C - gas) * st[i].p;
            gas = C;
            gas -= (st[k].d - st[i].d) / D2;
            i = k;
        }
    }
    cout.precision(2);
    cout.setf(ios::fixed);
    cout << cost << '\n';
    return 0;
}
