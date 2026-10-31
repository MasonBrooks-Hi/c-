#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) if (n % i == 0) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    if (!(cin >> a >> b)) return 0;
    vector<int> res;
    for (int len = 1; len <= 7; len++) {
        int half = (len + 1) / 2;
        int start = (len == 1) ? 1 : (int)pow(10, half - 1);
        int end = (int)pow(10, half) - 1;
        for (int first = start; first <= end; first++) {
            string s = to_string(first);
            string rev = s; reverse(rev.begin(), rev.end());
            string pal = (len % 2 == 0) ? (s + rev) : (s + rev.substr(1));
            int val = stoi(pal);
            if (val > b) { /* continue larger */ }
            if (val < a || val > b) continue;
            if (isPrime(val)) res.push_back(val);
        }
    }
    for (int v : res) cout << v << "\n";
    return 0;
}
