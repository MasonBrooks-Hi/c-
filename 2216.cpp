#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

const long long MOD = 10000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    if (!getline(cin, s)) return 0;
    vector<long long> nums;
    vector<char> ops;
    int i = 0, n = s.length();
    while (i < n) {
        if (s[i] == ' ') { i++; continue; }
        if (isdigit(s[i])) {
            long long num = 0;
            while (i < n && isdigit(s[i])) { num = num * 10 + (s[i] - '0'); i++; }
            nums.push_back(num % MOD);
        } else {
            ops.push_back(s[i]);
            i++;
        }
    }
    long long total = 0, term = nums[0] % MOD;
    for (int k = 1; k < (int)nums.size(); k++) {
        if (ops[k - 1] == '*') term = (term * nums[k]) % MOD;
        else { total = (total + term) % MOD; term = nums[k] % MOD; }
    }
    total = (total + term) % MOD;
    cout << total << "\n";
    return 0;
}
