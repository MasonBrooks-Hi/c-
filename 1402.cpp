#include <iostream>
using namespace std;

int main() {
    long long N;
    if (!(cin >> N)) return 0;
    long long L = 0, sum = 0;
    while (true) {
        long long nxt = sum + (L + 1) * (L + 2) / 2;
        if (nxt > N) break;
        sum = nxt;
        L++;
    }
    cout << L << "\n" << (N - sum) << "\n";
    return 0;
}
