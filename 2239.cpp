#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int M;
    if (!(cin >> M)) return 0;
    while (M--) {
        string L;
        int N;
        cin >> L >> N;
        int len = L.length();
        N %= len;
        string res = L.substr(len - N) + L.substr(0, len - N);
        cout << res << "\n";
    }
    return 0;
}
