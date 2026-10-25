#include <iostream>
using namespace std;
int main() {
    int n, mx = 0, cur = 0, sys, dia;
    if (!(cin >> n)) return 0;
    for (int i = 0; i < n; i++) {
        cin >> sys >> dia;
        if (sys >= 90 && sys <= 140 && dia >= 60 && dia <= 90) {
            cur++;
            if (cur > mx) mx = cur;
        } else {
            cur = 0;
        }
    }
    cout << mx << "\n";
    return 0;
}
