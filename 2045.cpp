#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    set<int> seen;
    vector<int> out;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (seen.insert(x).second) out.push_back(x); // 保留第一次出现的
    }
    for (size_t i = 0; i < out.size(); i++) {
        if (i) cout << ' ';
        cout << out[i];
    }
    cout << '\n';
    return 0;
}
