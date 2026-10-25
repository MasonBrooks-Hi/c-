#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    if (!(cin >> n)) return 0;
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++)
        if (isPrime[i])
            for (int j = i * i; j <= n; j += i) isPrime[j] = false;
    vector<int> primes;
    for (int i = 2; i <= n; i++)
        if (isPrime[i]) primes.push_back(i);
    int P = (int)primes.size();
    int maxLen = 0, best = 0;
    for (int i = 0; i < P; i++) {
        long long sum = 0;
        for (int j = i; j < P; j++) {
            sum += primes[j];
            if (sum > n) break;
            int len = j - i + 1;
            if (isPrime[(int)sum]) {
                if (len > maxLen || (len == maxLen && (int)sum > best)) {
                    maxLen = len;
                    best = (int)sum;
                }
            }
        }
    }
    cout << best << "\n";
    return 0;
}
