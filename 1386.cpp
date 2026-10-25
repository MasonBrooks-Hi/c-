#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<int> target(n);
    for (int i = 0; i < n; i++) cin >> target[i];
    queue<int> q;
    int next = 1;
    vector<int> st;
    bool possible = true;
    for (int i = 0; i < n; i++) {
        while (next <= n && (st.empty() || st.back() != target[i])) {
            st.push_back(next++);
        }
        if (!st.empty() && st.back() == target[i]) st.pop_back();
        else { possible = false; break; }
    }
    cout << (possible ? "Possible" : "Impossible") << "\n";
    return 0;
}
