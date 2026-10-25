#include <iostream>
using namespace std;
int main() {
    int n;
    if (!(cin >> n)) return 0;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 7 == 0) continue;
        int t = i; bool has = false;
        while (t > 0) { if (t % 10 == 7) { has = true; break; } t /= 10; }
        if (has) continue;
        sum += (long long)i * i;
    }
    cout << sum << "\n";
    return 0;
}
