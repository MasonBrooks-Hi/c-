#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long N;
    if (!(cin >> N)) return 0;
    long long cnt = 0;
    for (long long i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            cnt++;
            if (i * i != N) cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}
