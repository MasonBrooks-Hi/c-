#include <iostream>
using namespace std;

int main() {
    long long a1, a2, n;
    cin >> a1 >> a2 >> n;
    long long z = a1 + (n - 1) * (a2 - a1);
    cout << z << endl;
    return 0;
}
