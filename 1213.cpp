#include <iostream>
using namespace std;

int popcnt(int x) {
    int c = 0;
    while (x) {
        c += x & 1;
        x >>= 1;
    }
    return c;
}

int main() {
    int m;
    if (!(cin >> m)) return 0;
    while (m--) {
        int n;
        cin >> n;
        int bits = 0;
        int tmp = n;
        while (tmp) {
            bits++;
            tmp >>= 1;
        }
        int s = (bits - 1) + (popcnt(n) - 1);
        cout << s << "\n";
    }
    return 0;
}
