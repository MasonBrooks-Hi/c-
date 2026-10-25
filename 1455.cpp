#include <iostream>
using namespace std;

long long sum(int n) {
    if (n == 0) return 0;
    return n + sum(n - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    if (!(cin >> n)) return 0;
    cout << sum(n) << "\n";
    return 0;
}
