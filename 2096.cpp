#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    int li = 0, zhang = 0, fun = 0;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s == "Li") li++;
        else if (s == "Zhang") zhang++;
        else if (s == "Fun") fun++;
    }
    cout << "Li:" << li << '\n';
    cout << "Zhang:" << zhang << '\n';
    cout << "Fun:" << fun << '\n';
    return 0;
}
