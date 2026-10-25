#include <iostream>
using namespace std;

int main() {
    int A;
    while (cin >> A && A != 0) {
        int low = A & (-A);
        cout << low << "\n";
    }
    return 0;
}
