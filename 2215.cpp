#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    if (!(cin >> n >> x)) return 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int t = i;
        while (t > 0) {
            if (t % 10 == x) cnt++;
            t /= 10;
        }
    }
    cout << cnt << "\n";
    return 0;
}
