#include <iostream>
#include <vector>
using namespace std;

int cost0(int d) {
    return (d >= 5 ? 1 : 0) + (d % 5 > 0 ? 1 : 0);
}
int moveMin(int o, int n) {
    int a = ((o >= 5) != (n >= 5)) ? 1 : 0;
    int b = ((o % 5) != (n % 5)) ? 1 : 0;
    return a + b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    if (!(cin >> N)) return 0;
    vector<int> T; // digits least significant first
    long long total = 0;
    for (int i = 0; i < N; i++) {
        long long A;
        cin >> A;
        int carry = 0;
        int pos = 0;
        while (A > 0 || carry > 0) {
            int o = (pos < (int)T.size()) ? T[pos] : 0;
            int a_d = (int)(A % 10);
            A /= 10;
            int s = o + a_d + carry;
            int nxt = s % 10;
            int carry_out = s / 10;
            if (carry_out == 1) total += cost0(o) + cost0(nxt);
            else total += moveMin(o, nxt);
            if (pos < (int)T.size()) T[pos] = nxt;
            else T.push_back(nxt);
            carry = carry_out;
            pos++;
        }
    }
    cout << total << "\n";
    return 0;
}
