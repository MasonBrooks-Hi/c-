#include <iostream>
using namespace std;
int main() {
    int m, n;
    cin >> m >> n;
    int sum = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if (i == 0 || i == m - 1 || j == 0 || j == n - 1) sum += x;
        }
    cout << sum << "\n";
    return 0;
}
