#include <iostream>
using namespace std;
int main() {
    int a[5][5];
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) cin >> a[i][j];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            bool rmax = true, cmin = true;
            for (int k = 0; k < 5; k++) {
                if (a[i][k] > a[i][j]) rmax = false;
                if (a[k][j] < a[i][j]) cmin = false;
            }
            if (rmax && cmin) {
                cout << i + 1 << " " << j + 1 << " " << a[i][j] << "\n";
                return 0;
            }
        }
    }
    cout << "not found\n";
    return 0;
}
