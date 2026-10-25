#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    string s;
    if (cin >> s) {
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;
        int best = 0;
        for (int i = 1; i < 26; ++i) if (cnt[i] > cnt[best]) best = i;
        cout << (char)('a' + best) << " " << cnt[best] << endl;
    }
    return 0;
}
