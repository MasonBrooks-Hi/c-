#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    if (!(cin >> n >> k)) return 0;
    int p = 1;
    for (int i = 1; i < k; i++) p *= 10;
    int d = (n / p) % 10;
    cout << d << "\n";
    return 0;
}
