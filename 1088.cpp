#include <iostream>
#include <string>
using namespace std;

int main() {
    string c;
    cin >> c;
    bool any = false;
    for (int k = 2; k <= 9; k++) {
        int rem = 0;
        for (char ch : c) rem = (rem * 10 + (ch - '0')) % k;
        if (rem == 0) {
            if (any) cout << " ";
            cout << k;
            any = true;
        }
    }
    if (!any) cout << "none";
    cout << endl;
    return 0;
}
