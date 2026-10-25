#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int mid = n / 2 + 1;
    for (int i = 1; i <= n; i++) {
        int d = (i <= mid) ? (i - 1) : (n - i);
        int stars = n - 2 * d;
        int lead = (i == 1 || i == n) ? 0 : 1;
        for (int k = 0; k < lead; k++) cout << " ";
        for (int k = 0; k < stars; k++) cout << "*";
        cout << "\n";
    }
    return 0;
}
