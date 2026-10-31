#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 20123;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    if (!(cin >> N >> M)) return 0;
    vector<vector<int>> stair(N + 1, vector<int>(M));
    vector<vector<int>> ind(N + 1, vector<int>(M));
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> stair[i][j] >> ind[i][j];
        }
    }
    int start;
    cin >> start;
    long long sum = 0;
    int r = start;
    for (int f = 1; f <= N; f++) {
        sum = (sum + ind[f][r]) % MOD;
        // collect stair rooms on floor f
        vector<int> pos;
        for (int j = 0; j < M; j++) if (stair[f][j]) pos.push_back(j);
        int cnt = pos.size();
        int x = ind[f][r];
        int target;
        // find index of r in pos if it is a stair room
        auto it = lower_bound(pos.begin(), pos.end(), r);
        bool rIsStair = (it != pos.end() && *it == r);
        if (rIsStair) {
            int idx = it - pos.begin();
            target = pos[(idx + (x - 1)) % cnt];
        } else {
            // first stair room after r (counterclockwise = increasing index, wrap)
            int startIdx;
            if (it != pos.end()) startIdx = it - pos.begin();
            else startIdx = 0;
            target = pos[(startIdx + (x - 1)) % cnt];
        }
        r = target;
    }
    cout << sum % MOD << "\n";
    return 0;
}
