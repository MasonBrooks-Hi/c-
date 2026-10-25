#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    if (cin >> s) {
        long long rem = 0;
        string quo;
        for (char ch : s) {
            int d = ch - '0';
            rem = rem * 10 + d;
            int q = (int)(rem / 13);
            if (!(quo.empty() && q == 0)) quo.push_back((char)('0' + q));
            rem = rem % 13;
        }
        if (quo.empty()) quo = "0";
        cout << quo << "\n" << rem << endl;
    }
    return 0;
}
