#include <iostream>
using namespace std;
int main() {
    int n;
    if (cin >> n) {
        int f[1005];
        f[1] = 1; f[2] = 1;
        for (int i = 3; i <= 1000; ++i) f[i] = (f[i - 1] + f[i - 2]) % 1000;
        while (n--) {
            int a;
            cin >> a;
            cout << f[a] << "\n";
        }
    }
    return 0;
}
