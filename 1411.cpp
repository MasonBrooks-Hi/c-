#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<int> A(n), B(m);
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < m; i++) cin >> B[i];

    auto solve = [&](const vector<int>& seq) -> pair<long long, long long> {
        long long score = 0, opp = 0;
        int L = (int)seq.size();
        for (int i = 0; i < L; i++) {
            int v = seq[i];
            if (i == L - 1) {
                if (v == 0) {
                    opp += 4;
                } else {
                    int reds_potted = 0;
                    for (int k = 0; k < i; k++)
                        if ((k % 2 == 0) && seq[k] == 1) reds_potted++;
                    int reds_remaining = 15 - reds_potted;
                    bool expected_red = (reds_remaining > 0) && (i % 2 == 0);
                    if (expected_red) {
                        if (v == 1) score += 1;
                        else opp += (v > 4 ? v : 4);
                    } else {
                        if (v == 1) opp += 4;
                        else if (v >= 2 && v <= 7) score += v;
                    }
                }
            } else {
                score += v;
            }
        }
        return {score, opp};
    };

    auto [sA, oA] = solve(A);
    auto [sB, oB] = solve(B);
    long long A_total = sA + oB;
    long long B_total = sB + oA;
    cout << A_total << " " << B_total << "\n";
    return 0;
}
