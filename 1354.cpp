#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s;
    if (!(cin >> s)) return 0;
    sort(s.begin(), s.end());
    do {
        cout << s << "\n";
    } while (next_permutation(s.begin(), s.end()));
    return 0;
}
