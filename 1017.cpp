#include <iostream>
using namespace std;
int main() {
    int n, sum = 0, x;
    if (!(cin >> n)) return 0;
    for (int i = 0; i < n - 1; i++) { cin >> x; sum += x; }
    cout << (n - 2) * 180 - sum << "\n";
    return 0;
}
