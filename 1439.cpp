#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    if (!(cin >> N)) return 0;
    vector<long long> a(N);
    long long mx = -2000000000, sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        if (a[i] > mx) mx = a[i];
        sum += a[i];
    }
    cout << sum - mx << "\n";
    return 0;
}
