// 1673 确定进制
// 读入 p、q、r 三个整数（十进制表示的数位），寻找最小进制 B(2<=B<=40) 使得
// 在 B 进制下 p * q = r。数字本身要合法（每一位 < B）。
#include <iostream>
#include <string>
using namespace std;

// 把 s 按 B 进制求值；若存在 >= B 的数位则返回 false
bool eval(const string &s, int B, long long &out) {
    long long v = 0;
    for (char ch : s) {
        if (ch < '0' || ch > '9') return false;
        int d = ch - '0';
        if (d >= B) return false;
        v = v * B + d;
    }
    out = v;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string p, q, r;
    if (!(cin >> p >> q >> r)) return 0;

    for (int B = 2; B <= 40; B++) {
        long long vp, vq, vr;
        if (!eval(p, B, vp)) continue;
        if (!eval(q, B, vq)) continue;
        if (!eval(r, B, vr)) continue;
        if ((__int128)vp * vq == (__int128)vr) {
            cout << B << "\n";
            return 0;
        }
    }
    cout << 0 << "\n";
    return 0;
}
