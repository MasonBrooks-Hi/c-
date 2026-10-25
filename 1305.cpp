#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int a, b, c;
    if (cin >> a >> b >> c) {
        cout << min({a, b, c}) << endl;
    }
    return 0;
}
