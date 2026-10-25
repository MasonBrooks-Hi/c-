#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<string> pal;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        string r = s;
        reverse(r.begin(), r.end());
        if (r == s) pal.push_back(s);
    }
    sort(pal.begin(), pal.end(), [](const string &a, const string &b) {
        if (a.size() != b.size()) return a.size() < b.size();
        return a < b;
    });
    for (auto &s : pal) cout << s << "\n";
    return 0;
}
