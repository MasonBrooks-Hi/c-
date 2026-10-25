// 1782 字符串数组排序问题
// Modes: inc, dec, ncinc, ncdec. Trim leading/trailing spaces of each string.
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

static string trimStr(const string &s) {
    size_t i = 0, j = s.size();
    while (i < j && isspace((unsigned char)s[i])) i++;
    while (j > i && isspace((unsigned char)s[j - 1])) j--;
    return s.substr(i, j - i);
}

int main() {
    string mode;
    getline(cin, mode);
    mode = trimStr(mode);
    int n;
    if (!(cin >> n)) return 0;
    string line;
    getline(cin, line); // consume end of line
    vector<string> v;
    for (int i = 0; i < n; i++) {
        if (!getline(cin, line)) line = "";
        v.push_back(trimStr(line));
    }
    bool nc = (mode == "ncinc" || mode == "ncdec");
    bool inc = (mode == "inc" || mode == "ncinc");
    stable_sort(v.begin(), v.end(), [&](const string &a, const string &b) {
        if (nc) {
            size_t i = 0;
            while (i < a.size() && i < b.size()) {
                unsigned char ca = tolower((unsigned char)a[i]);
                unsigned char cb = tolower((unsigned char)b[i]);
                if (ca != cb) return inc ? ca < cb : ca > cb;
                i++;
            }
            if (a.size() != b.size()) return inc ? a.size() < b.size() : a.size() > b.size();
            return false;
        }
        return inc ? a < b : a > b;
    });
    for (auto &s : v) printf("%s\n", s.c_str());
    return 0;
}
