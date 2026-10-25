#include <iostream>
using namespace std;
int main() {
    int n;
    if (cin >> n) {
        if (n >= 86) cout << "VERY GOOD" << endl;
        else if (n >= 60) cout << "GOOD" << endl;
        else cout << "BAD" << endl;
    }
    return 0;
}
