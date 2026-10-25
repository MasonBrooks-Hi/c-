#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, L;
    if (!(cin >> N >> L)) return 0;
    vector<int> d(N);
    for (int i = 0; i < N; i++) cin >> d[i];
    set<int> primes;
    for (int i = 0; i + L <= N; i++) {
        if (d[i] == 0) continue; // leading zero
        int num = 0;
        for (int j = 0; j < L; j++) num = num * 10 + d[i + j];
        if (isPrime(num)) primes.insert(num);
    }
    bool first = true;
    for (int p : primes) {
        if (!first) cout << ",";
        cout << p;
        first = false;
    }
    cout << "\n";
    return 0;
}
