#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    string s;
    if (cin >> s) {
        string t = s;
        sort(t.begin(), t.end(), greater<char>());
        cout << t << endl;
    }
    return 0;
}
