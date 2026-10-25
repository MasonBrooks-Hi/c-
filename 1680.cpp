// 1680 玛雅历：Haab -> Tzolkin
// Haab：19 个月，前 18 个月各 20 天（日期 0..19），最后 uayet 月 5 天（0..4）。
// Tzolkin：数字 1..13 循环，名称 20 个循环，年长 260 天。
// 输入行形如 "10. zac 0"（日期后的 '.' 与日期同属一个词，或单独成词均可）。
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <cctype>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const string HAAB_MONTH[19] = {
        "pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen",
        "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"
    };
    const string TZOLKIN_NAME[20] = {
        "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat",
        "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban",
        "eznab", "canac", "ahau"
    };

    map<string, int> monthIndex;
    for (int i = 0; i < 19; i++) monthIndex[HAAB_MONTH[i]] = i;

    int n;
    if (!(cin >> n)) return 0;

    string dummy;
    getline(cin, dummy);   // 读掉第一行剩余部分

    cout << n << "\n";
    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);

        vector<string> tok;
        {
            // 去掉所有 '.'，再按空白切分，得到 日 月 年
            string clean;
            for (char ch : line) if (ch != '.') clean += ch;
            istringstream ss(clean);
            string t;
            while (ss >> t) tok.push_back(t);
        }

        string dayStr, monthStr, yearStr;
        if (tok.size() >= 1) dayStr = tok[0];
        if (tok.size() >= 2) monthStr = tok[1];
        if (tok.size() >= 3) yearStr = tok[2];

        long long day = dayStr.empty() ? 0 : strtoll(dayStr.c_str(), nullptr, 10);
        long long year = yearStr.empty() ? 0 : strtoll(yearStr.c_str(), nullptr, 10);

        int mi = monthIndex.count(monthStr) ? monthIndex[monthStr] : 0;
        long long total = year * 365 + (long long)mi * 20 + day;

        int number = (int)(total % 13) + 1;
        const string &name = TZOLKIN_NAME[total % 20];
        long long tzYear = total / 260;

        cout << number << " " << name << " " << tzYear << "\n";
    }
    return 0;
}
