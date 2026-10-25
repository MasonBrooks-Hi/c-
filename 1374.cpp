#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    if (!(cin >> m >> n)) return 0;
    vector<int> v;
    for (int i = 1; i <= n; i++) v.push_back(i);
    // first deletion: step 2
    int step = 2;
    vector<int> nv;
    for (size_t i = 0; i < v.size(); i++)
        if ((i + 1) % step != 0) nv.push_back(v[i]);
    v = nv;
    int idx = 2; // 1-based index of next lucky number to use as step
    while (idx <= (int)v.size()) {
        step = v[idx - 1];
        nv.clear();
        for (size_t i = 0; i < v.size(); i++)
            if ((i + 1) % step != 0) nv.push_back(v[i]);
        v = nv;
        idx++;
    }
    int cnt = 0;
    for (int x : v)
        if (x > m && x < n) cnt++;
    cout << cnt << "\n";
    return 0;
}
