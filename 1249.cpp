#include <iostream>
using namespace std;

int main() {
    int K;
    if (!(cin >> K)) return 0;
    while (K--) {
        int n;
        cin >> n;
        int r = 0, cnt = 0;
        while (true) {
            r = (r * 10 + 1) % n;
            cnt++;
            if (r == 0) break;
        }
        cout << cnt << "\n";
    }
    return 0;
}
