// 1678 不吉利日期
// 已知某年 1 月 1 日是星期 w（1=周一 ... 7=周日），该年不是闰年。
// 求所有 13 日是星期五（星期 5）的月份。
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int w;
    if (!(cin >> w)) return 0;

    const int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int offset = 0;   // 该月 1 日相对 1 月 1 日的天数偏移
    for (int m = 1; m <= 12; m++) {
        int day13 = ((w - 1 + offset + 12) % 7) + 1;
        if (day13 == 5) cout << m << "\n";
        offset += days[m];
    }
    return 0;
}
