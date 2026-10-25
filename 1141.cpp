#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    int n;
    cin >> n;
    int total = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int cnt = x / 70 + (x % 70 ? 1 : 0);
        total += cnt;
    }
    double cost = total * 0.1;
    cout << fixed << setprecision(1) << cost << "\n";
    return 0;
}
