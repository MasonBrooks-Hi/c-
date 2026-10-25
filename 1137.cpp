#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (i != 1 && i != n) cout << " ";
        for (int j = 0; j < 2 * i - 1; j++) cout << i;
        cout << "\n";
    }
    return 0;
}
