// 1738 碎纸机
// Try every way of cutting the number; maximize sum of parts not exceeding target.
// Ties -> rejected; no valid cut (even all single digits) -> error.
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    long long target;
    string num;
    while (cin >> target >> num) {
        if (target == 0 && num == "0") break;
        int L = (int)num.size();
        long long best = -1;
        int ways = 0;
        string bestOut;
        for (int mask = 0; mask < (1 << (L - 1)); mask++) {
            vector<string> parts;
            int start = 0;
            for (int i = 0; i < L - 1; i++) {
                if (mask & (1 << i)) {
                    parts.push_back(num.substr(start, i + 1 - start));
                    start = i + 1;
                }
            }
            parts.push_back(num.substr(start));
            long long sum = 0;
            for (auto &p : parts) sum += stoll(p);
            if (sum <= target) {
                string out;
                for (size_t i = 0; i < parts.size(); i++) {
                    if (i) out += " ";
                    out += parts[i];
                }
                if (sum > best) { best = sum; ways = 1; bestOut = out; }
                else if (sum == best) ways++;
            }
        }
        if (best < 0) printf("error\n");
        else if (ways > 1) printf("rejected\n");
        else printf("%lld %s\n", best, bestOut.c_str());
    }
    return 0;
}
