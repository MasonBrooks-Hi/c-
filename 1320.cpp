#include <iostream>
using namespace std;
int main() {
    int n, k;
    if (cin >> n >> k) {
        cout << (2 * n + k - 1) / k << endl;
    }
    return 0;
}
