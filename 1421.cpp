#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long N;
    if (!(cin >> N)) return 0;
    long long tri = N * N;
    long long stick = 3 * N * (N + 1) / 2;
    cout << tri << "\n" << stick << "\n";
    return 0;
}
