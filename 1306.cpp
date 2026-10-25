#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int a, b, c;
    if (cin >> a >> b >> c) {
        int m = min({a, b, c});
        if (m == a) cout << 1 << endl;
        else if (m == b) cout << 2 << endl;
        else cout << 3 << endl;
    }
    return 0;
}
