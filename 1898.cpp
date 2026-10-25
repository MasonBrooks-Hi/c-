#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; (long long)i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}

int main() {
    int L;
    if (!(cin >> L)) return 0;
    // 0,1,...,9 排成一圈，从 1..9 出发顺时针取 L 个数字
    vector<int> primes;
    for (int s = 1; s <= 9; s++) {
        int num = 0;
        for (int k = 0; k < L; k++) num = num * 10 + (s + k) % 10;
        if (isPrime(num)) primes.push_back(num);
    }
    for (size_t i = 0; i < primes.size(); i++) {
        if (i) cout << ',';
        cout << primes[i];
    }
    cout << '\n';
    return 0;
}
