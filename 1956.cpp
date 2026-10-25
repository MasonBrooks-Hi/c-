#include <iostream>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    long long odd = 0, even = 0;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        if (x % 2 == 1) odd += x;
        else even += x;
    }
    cout << odd << '\n' << even << '\n';
    return 0;
}
