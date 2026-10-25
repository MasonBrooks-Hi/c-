#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    bool d3 = (n % 3 == 0), d5 = (n % 5 == 0), d7 = (n % 7 == 0);
    int cnt = (d3 ? 1 : 0) + (d5 ? 1 : 0) + (d7 ? 1 : 0);
    if (cnt == 0) {
        cout << "no\n";
    } else {
        bool first = true;
        if (d3) { if (!first) cout << " "; cout << 3; first = false; }
        if (d5) { if (!first) cout << " "; cout << 5; first = false; }
        if (d7) { if (!first) cout << " "; cout << 7; first = false; }
        cout << endl;
    }
    return 0;
}
