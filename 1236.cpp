#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;
    set<int> s;
    for (int i = 0; i < n + m; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    bool first = true;
    for (int v : s) {
        if (!first) cout << " ";
        cout << v;
        first = false;
    }
    cout << "\n";
    return 0;
}
