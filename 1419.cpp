#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    if (!(cin >> s)) return 0;
    map<char, int> freq;
    for (char c : s) freq[c]++;
    vector<pair<int, char>> v;
    for (auto& p : freq) v.push_back({p.second, p.first});
    sort(v.begin(), v.end(), [](const pair<int, char>& a, const pair<int, char>& b) {
        if (a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    });
    for (auto& p : v) cout << p.second << " " << p.first << "\n";
    return 0;
}
