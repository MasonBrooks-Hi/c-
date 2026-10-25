#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<long long> w(n);
    long long total = 0;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
        total += w[i];
    }
    bitset<2000001> bs;
    bs[0] = 1;
    for (int i = 0; i < n; i++) {
        bs |= bs << w[i];
    }
    long long best = 0;
    for (int s = 0; s <= total / 2; s++) {
        if (bs[s]) best = s;
    }
    cout << total - 2 * best << "\n";
    return 0;
}
