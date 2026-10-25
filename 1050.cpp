#include <iostream>
using namespace std;
int main() {
    int L, R, c = 0;
    if (!(cin >> L >> R)) return 0;
    for (int i = L; i <= R; i++) {
        int t = i;
        while (t > 0) { if (t % 10 == 2) c++; t /= 10; }
    }
    cout << c << "\n";
    return 0;
}
