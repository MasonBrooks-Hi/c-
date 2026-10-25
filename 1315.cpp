#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int a, b, c;
    if (cin >> a >> b >> c) {
        int v[3] = {a, b, c};
        sort(v, v + 3);
        if (v[0] + v[1] > v[2]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
