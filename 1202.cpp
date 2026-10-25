#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n, 0));
    int cnt = 1;
    for (int sum = 0; sum <= 2 * (n - 1); sum++) {
        int i0 = max(0, sum - (n - 1));
        int i1 = min(n - 1, sum);
        if ((sum + 1) % 2 == 1) {
            for (int i = i1; i >= i0; i--) a[i][sum - i] = cnt++;
        } else {
            for (int i = i0; i <= i1; i++) a[i][sum - i] = cnt++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j) cout << ' ';
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}
