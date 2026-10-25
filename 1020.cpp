#include <iostream>
using namespace std;
int main() {
    int n, x, c1 = 0, c5 = 0, c10 = 0;
    if (!(cin >> n)) return 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 1) c1++;
        else if (x == 5) c5++;
        else if (x == 10) c10++;
    }
    cout << c1 << "\n" << c5 << "\n" << c10 << "\n";
    return 0;
}
