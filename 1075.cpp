#include <iostream>
using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    int eaten = (y + x - 1) / x;
    int rem = n - eaten;
    if (rem < 0) rem = 0;
    cout << rem << endl;
    return 0;
}
