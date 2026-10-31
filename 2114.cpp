#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Block {
    int x, y, h;
};

bool operator<(const Block& a, const Block& b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

int main() {
    int n, caseno = 0;
    while (cin >> n && n != 0) {
        caseno++;
        vector<Block> v;
        for (int i = 0; i < n; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            int arr[3] = {x, y, z};
            sort(arr, arr + 3);
            v.push_back({arr[0], arr[1], arr[2]});
            v.push_back({arr[0], arr[2], arr[1]});
            v.push_back({arr[1], arr[2], arr[0]});
        }
        sort(v.begin(), v.end());
        vector<long long> dp(v.size(), 0);
        long long ans = 0;
        for (size_t i = 0; i < v.size(); i++) {
            dp[i] = v[i].h;
            for (size_t j = 0; j < i; j++)
                if (v[j].x < v[i].x && v[j].y < v[i].y)
                    dp[i] = max(dp[i], dp[j] + v[i].h);
            if (dp[i] > ans) ans = dp[i];
        }
        cout << "Case " << caseno << ": maximum height = " << ans << '\n';
    }
    return 0;
}
