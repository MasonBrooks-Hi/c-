#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;
int main() {
    int p1, p2, p3;
    cin >> p1 >> p2 >> p3;
    string s;
    cin >> s;
    string out;
    int n = (int)s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] != '-') { out += s[i]; continue; }
        if (i == 0 || i == n - 1) { out += '-'; continue; }
        char L = s[i - 1], R = s[i + 1];
        bool bothLow = islower((unsigned char)L) && islower((unsigned char)R);
        bool bothDig = isdigit((unsigned char)L) && isdigit((unsigned char)R);
        if ((bothLow || bothDig) && R > L) {
            string mid;
            for (char c = L + 1; c < R; c++) {
                char ch = c;
                if (p1 == 2 && isalpha((unsigned char)ch)) ch = toupper((unsigned char)ch);
                else if (p1 == 3) ch = '*';
                for (int k = 0; k < p2; k++) mid += ch;
            }
            if (p3 == 2) { string r = mid; reverse(r.begin(), r.end()); mid = r; }
            out += mid;
        } else {
            out += '-';
        }
    }
    cout << out << "\n";
    return 0;
}
