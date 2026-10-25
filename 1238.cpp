#include <iostream>
#include <set>
using namespace std;

int main() {
    int C;
    if (!(cin >> C)) return 0;
    while (C--) {
        int n;
        cin >> n;
        set<int> s;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            s.insert(x);
        }
        if (s.size() < 2) cout << "NO\n";
        else {
            auto it = s.begin();
            ++it;
            cout << *it << "\n";
        }
    }
    return 0;
}
