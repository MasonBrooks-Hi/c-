#include <iostream>
using namespace std;
int main() {
    int w;
    if (cin >> w) {
        if (w < 10) cout << "A" << endl;
        else if (w < 20) cout << "B" << endl;
        else if (w < 40) cout << "C" << endl;
        else if (w < 50) cout << "D" << endl;
        else cout << "E" << endl;
    }
    return 0;
}
