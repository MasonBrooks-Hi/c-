// 1846 趣味填空
// Insert one '+' in the left number so that left = right. Output the equation or "Impossible!".
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    while (!s.empty() && (s.back() == '\r' || s.back() == '\n')) s.pop_back();
    size_t eq = s.find('=');
    if (eq == string::npos) { printf("Impossible!\n"); return 0; }
    string L = s.substr(0, eq), R = s.substr(eq + 1);
    long long rv = 0;
    try { rv = stoll(R); } catch (...) { rv = -1; }
    for (size_t i = 1; i < L.size(); i++) {
        string lp = L.substr(0, i), rp = L.substr(i);
        long long lv = 0, rv2 = 0;
        bool ok = true;
        try { lv = stoll(lp); rv2 = stoll(rp); } catch (...) { ok = false; }
        if (ok && lv + rv2 == rv) {
            printf("%s+%s=%s\n", lp.c_str(), rp.c_str(), R.c_str());
            return 0;
        }
    }
    printf("Impossible!\n");
    return 0;
}
