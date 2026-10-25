#include <iostream>
using namespace std;
int main() {
    int n;
    if (cin >> n) {
        int p[1005];
        p[1] = 1; p[2] = 2;
        for (int i = 3; i < 1000; ++i) p[i] = (2 * p[i - 1] + p[i - 2]) % 32767;
        while (n--) {
            int k;
            cin >> k;
            cout << p[k] << "\n";
        }
    }
    return 0;
}
