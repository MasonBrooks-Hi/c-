#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long k, p;
    if (!(cin >> k >> p)) return 0;
    long long base = k / p, rem = k % p;
    // 输出：先 base (共 p-rem 个)，再 base+1 (共 rem 个)，非递减
    vector<long long> parts;
    for (long long i = 0; i < p - rem; i++) parts.push_back(base);
    for (long long i = 0; i < rem; i++) parts.push_back(base + 1);
    long long prod = 1;
    for (size_t i = 0; i < parts.size(); i++) {
        if (i) cout << '*';
        cout << parts[i];
        prod *= parts[i];
    }
    cout << '=' << prod << '\n';
    return 0;
}
