#include <iostream>
using namespace std;
int main() {
    int n, c = 0;
    if (!(cin >> n)) return 0;
    for (int i = 1; i <= n; i++) {
        int t = i;
        while (t > 0) { if (t % 10 == 1) c++; t /= 10; }
    }
    cout << c << "\n";
    return 0;
}
