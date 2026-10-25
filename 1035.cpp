#include <iostream>
using namespace std;
int main() {
    int n, c = 0, x;
    if (!(cin >> n)) return 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        int u = x % 10, t = (x / 10) % 10, h = (x / 100) % 10, th = x / 1000;
        if (u - th - h - t > 0) c++;
    }
    cout << c << "\n";
    return 0;
}
