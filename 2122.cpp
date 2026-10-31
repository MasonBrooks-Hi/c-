#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    int h;
    cin >> h;
    vector<int> F(n + 1), D(n + 1);
    for (int i = 1; i <= n; i++) cin >> F[i];
    for (int i = 1; i <= n; i++) cin >> D[i];
    vector<int> T(n); // travel times between pond i and i+1
    for (int i = 1; i < n; i++) cin >> T[i];
    int total_units = h * 12;
    long long ans = 0;
    int travel = 0;
    for (int k = 1; k <= n; k++) {
        if (k > 1) travel += T[k - 1];
        int time_left = total_units - travel;
        if (time_left < 0) break;
        vector<int> fish(n + 1), dec(n + 1);
        for (int i = 1; i <= k; i++) { fish[i] = F[i]; dec[i] = D[i]; }
        long long got = 0;
        while (time_left > 0) {
            int best = 0;
            for (int i = 1; i <= k; i++)
                if (fish[i] > fish[best]) best = i;
            if (fish[best] <= 0) break;
            got += fish[best];
            fish[best] -= dec[best];
            if (fish[best] < 0) fish[best] = 0;
            time_left--;
        }
        if (got > ans) ans = got;
    }
    cout << ans << '\n';
    return 0;
}
