#include <iostream>
using namespace std;

int main() {
    int N;
    if (!(cin >> N)) return 0;
    while (N--) {
        long long n;
        cin >> n;
        cout << n * (n + 1) * (n + 2) / 6 << "\n";
    }
    return 0;
}
