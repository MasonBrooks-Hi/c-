#include <iostream>
#include <algorithm>
using namespace std;

int a[105], dp1[105], dp2[105];

int main() {
    int N;
    if (!(cin >> N)) return 0;
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = 1; i <= N; i++) {
        dp1[i] = 1;
        for (int j = 1; j < i; j++)
            if (a[j] < a[i]) dp1[i] = max(dp1[i], dp1[j] + 1);
    }
    for (int i = N; i >= 1; i--) {
        dp2[i] = 1;
        for (int j = i + 1; j <= N; j++)
            if (a[j] < a[i]) dp2[i] = max(dp2[i], dp2[j] + 1);
    }
    int best = 0;
    for (int i = 1; i <= N; i++) best = max(best, dp1[i] + dp2[i] - 1);
    cout << N - best << '\n';
    return 0;
}
