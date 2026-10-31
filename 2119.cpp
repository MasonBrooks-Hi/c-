#include <iostream>
#include <algorithm>
using namespace std;

int a[105][105];

int main() {
    int N;
    while (cin >> N && N != 0) {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) cin >> a[i][j];
        int ans = -2000000000;
        for (int top = 0; top < N; top++) {
            int col[105] = {0};
            for (int bot = top; bot < N; bot++) {
                for (int j = 0; j < N; j++) col[j] += a[bot][j];
                int cur = 0;
                for (int j = 0; j < N; j++) {
                    cur += col[j];
                    if (cur > ans) ans = cur;
                    if (cur < 0) cur = 0;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
