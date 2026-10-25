#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s;
    int m;
    if (!(cin >> s >> m)) return 0;
    vector<char> st;
    for (char c : s) {
        while (m > 0 && !st.empty() && st.back() > c) {
            st.pop_back();
            m--;
        }
        st.push_back(c);
    }
    while (m > 0 && !st.empty()) { st.pop_back(); m--; }
    // strip leading zeros
    size_t i = 0;
    while (i < st.size() && st[i] == '0') i++;
    if (i == st.size()) cout << "0\n";
    else { for (; i < st.size(); i++) cout << st[i]; cout << "\n"; }
    return 0;
}
