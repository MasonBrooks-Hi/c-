#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    bool fa = (a < 60), fb = (b < 60);
    if (fa != fb) cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
}
