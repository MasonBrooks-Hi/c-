// 1681 人民币支付：贪心，尽量使用大面额钞票
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int money;
    if (!(cin >> money)) return 0;

    const int denom[6] = {100, 50, 20, 10, 5, 1};
    for (int i = 0; i < 6; i++) {
        cout << money / denom[i] << "\n";
        money %= denom[i];
    }
    return 0;
}
