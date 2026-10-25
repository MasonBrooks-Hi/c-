#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    int minr = n, maxr = -1, minc = n, maxc = -1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 0) {
                if (i < minr) minr = i;
                if (i > maxr) maxr = i;
                if (j < minc) minc = j;
                if (j > maxc) maxc = j;
            }
        }
    int ans = 0;
    for (int i = minr + 1; i < maxr; i++)
        for (int j = minc + 1; j < maxc; j++)
            if (a[i][j] == 255) ans++;
    cout << ans << endl;
    return 0;
}
