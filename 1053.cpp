#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> primes;
    for (int i = 2; primes.size() < (size_t)n; i++) {
        bool ok = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) { ok = false; break; }
        }
        if (ok) primes.push_back(i);
    }
    cout << primes[n - 1] << endl;
    return 0;
}
