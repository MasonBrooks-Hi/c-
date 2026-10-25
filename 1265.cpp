#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a[3];
    if (!(cin >> a[0] >> a[1] >> a[2])) return 0;
    sort(a, a + 3, [](int x, int y) { return x > y; });
    cout << a[0] << " " << a[1] << " " << a[2] << "\n";
    return 0;
}
