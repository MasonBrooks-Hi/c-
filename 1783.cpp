// 1783 日志排序
// Sort records by duration (asc); tie -> earlier start time first. Preserve raw lines.
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cctype>
using namespace std;

struct Rec {
    string raw;
    string start;
    double dur;
};

int main() {
    vector<Rec> recs;
    string line;
    while (getline(cin, line)) {
        bool allws = true;
        for (char c : line)
            if (!isspace((unsigned char)c)) { allws = false; break; }
        if (allws) break; // empty line terminates
        istringstream iss(line);
        string name, date, tm, dur;
        if (!(iss >> name >> date >> tm >> dur)) continue;
        string start = date + " " + tm;
        size_t p = dur.find('(');
        double d = 0;
        try { d = stod(dur.substr(0, p)); } catch (...) { d = 0; }
        recs.push_back({line, start, d});
    }
    stable_sort(recs.begin(), recs.end(), [](const Rec &a, const Rec &b) {
        if (a.dur != b.dur) return a.dur < b.dur;
        return a.start < b.start;
    });
    for (auto &r : recs) printf("%s\n", r.raw.c_str());
    return 0;
}
