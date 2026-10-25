// 1661 素数个数：统计 2..n 中素数个数
#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int x) {
    if (x < 2) return false;
    for (int d = 2; d * d <= x; d++)
        if (x % d == 0) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    int cnt = 0;
    for (int i = 2; i <= n; i++)
        if (isPrime(i)) cnt++;
    cout << cnt << "\n";
    return 0;
}
