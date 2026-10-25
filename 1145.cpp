#include <iostream>
using namespace std;
int main() {
    int N;
    cin >> N;
    if (N == 0) { cout << "0B\n"; return 0; }
    string s;
    int x = N;
    while (x > 0) {
        s = (char)('0' + (x % 2)) + s;
        x /= 2;
    }
    cout << s << "B\n";
    return 0;
}
