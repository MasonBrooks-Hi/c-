#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    int eaten = 0;
    if (x > 0) eaten = (int)ceil((double)y / x);
    int rem = n - eaten;
    if (rem < 0) rem = 0;
    cout << rem << endl;
    return 0;
}
