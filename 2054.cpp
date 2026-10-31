#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s;
    if (!(cin >> s)) return 0;
    reverse(s.begin(), s.end());
    long long v = 0;
    for (char c : s) v = v * 10 + (c - '0');
    cout << v << '\n';
    return 0;
}
