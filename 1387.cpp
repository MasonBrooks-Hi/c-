#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    long long n;
    int d;
    if (!(cin >> n >> d)) return 0;
    if (n == 0) { cout << "0\n"; return 0; }
    vector<char> rev;
    while (n > 0) {
        int r = n % d;
        if (r < 10) rev.push_back('0' + r);
        else rev.push_back('A' + (r - 10));
        n /= d;
    }
    reverse(rev.begin(), rev.end());
    for (char c : rev) cout << c;
    cout << "\n";
    return 0;
}
