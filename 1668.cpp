// 1668 素数对：找出所有相差为 2 且均不超过 n 的素数对
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<bool> isPrime(n + 3, true);
    if (n + 2 >= 0) isPrime[0] = false;
    if (n + 2 >= 1) isPrime[1] = false;
    for (int i = 2; i * i <= n + 2; i++) {
        if (isPrime[i])
            for (int j = i * i; j <= n + 2; j += i) isPrime[j] = false;
    }

    bool found = false;
    for (int i = 2; i + 2 <= n; i++) {
        if (isPrime[i] && isPrime[i + 2]) {
            cout << i << " " << i + 2 << "\n";
            found = true;
        }
    }
    if (!found) cout << "empty\n";
    return 0;
}
