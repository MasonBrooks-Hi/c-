#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int total = 2 * n - 1;
    for (int i = 1; i <= total; i++) {
        if (i == 1) {
            for (int j = 0; j < n; j++) cout << "*";
            cout << "\n";
        } else if (i == n) {
            // center hollow row, no leading space
            int rstar = n - 3;
            if (rstar < 0) rstar = 0;
            for (int c = 0; c <= rstar; c++) {
                if (c == 0 || c == rstar) cout << "*";
                else cout << " ";
            }
            cout << "\n";
        } else if (i == total) {
            cout << " ";
            for (int j = 0; j < n; j++) cout << "*";
            cout << "\n";
        } else {
            // shoulder hollow row, one leading space
            int rstar = n - 2;
            for (int k = 0; k < 1; k++) cout << " ";
            for (int c = 1; c <= rstar; c++) {
                if (c == 1 || c == rstar) cout << "*";
                else cout << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
