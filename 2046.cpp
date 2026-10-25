#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    vector<string> names;
    string s;
    while (cin >> s) {
        if (s == "end") break;
        names.push_back(s);
    }
    sort(names.begin(), names.end());
    for (const string &name : names) cout << name << '\n';
    return 0;
}
