#include <iostream>
using namespace std;

int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    long long total = a + b;
    cout << total / c << " " << total % c << endl;
    return 0;
}
