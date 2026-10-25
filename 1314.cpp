#include <iostream>
using namespace std;
int main() {
    int t, k;
    if (cin >> t >> k) {
        if (t == k) cout << "tie" << endl;
        else if ((t == 1 && k == 2) || (t == 2 && k == 3) || (t == 3 && k == 1))
            cout << "win" << endl;
        else cout << "lose" << endl;
    }
    return 0;
}
