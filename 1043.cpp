#include <iostream>
using namespace std;
int main() {
    int n;
    if (!(cin >> n)) return 0;
    long long sum = 0, f = 1;
    for (int i = 1; i <= n; i++) { f *= i; sum += f; }
    cout << sum << "\n";
    return 0;
}
