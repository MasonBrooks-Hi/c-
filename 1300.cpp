#include <iostream>
using namespace std;
int main() {
    long long m, n;
    if (cin >> m >> n) {
        cout << (m + n - 1) / n << endl;
    }
    return 0;
}
