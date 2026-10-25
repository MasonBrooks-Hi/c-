#include <iostream>
#include <string>
using namespace std;

string s;

void solve(int l, int r) {
    if (l == r) {
        cout << (s[l] == '0' ? 'B' : 'I');
        return;
    }
    int mid = (l + r) / 2;
    solve(l, mid);
    solve(mid + 1, r);
    bool all0 = true, all1 = true;
    for (int i = l; i <= r; i++) {
        if (s[i] == '0') all1 = false;
        else all0 = false;
    }
    cout << (all0 ? 'B' : (all1 ? 'I' : 'F'));
}

int main() {
    int N;
    if (!(cin >> N)) return 0;
    cin >> s;
    solve(0, (int)s.size() - 1);
    cout << "\n";
    return 0;
}
