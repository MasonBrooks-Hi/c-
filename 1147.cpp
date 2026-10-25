#include <iostream>
using namespace std;
int fan(int m) {
    int s = 0;
    while (m > 0) { s += m % 10; m /= 10; }
    return s;
}
int main() {
    int n;
    cin >> n;
    cout << fan(n) << "\n";
    return 0;
}
