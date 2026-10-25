#include <iostream>
using namespace std;
int main() {
    int n;
    if (cin >> n) {
        int a = n / 100;
        int b = (n / 10) % 10;
        int c = n % 10;
        cout << c * 100 + b * 10 + a << endl;
    }
    return 0;
}
