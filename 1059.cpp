#include <iostream>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    if (x > y) cout << ">\n";
    else if (x == y) cout << "=\n";
    else cout << "<\n";
    return 0;
}
