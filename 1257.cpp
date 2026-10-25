#include <iostream>
using namespace std;

int main() {
    long long a, b;
    if (!(cin >> a >> b)) return 0;
    long long m = (a > b) ? a : b;
    cout << m * m << "\n";
    return 0;
}
