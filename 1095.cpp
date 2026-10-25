#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    string r;
    int n = (int)s.size();
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        r.push_back((char)(s[i] + s[j]));
    }
    cout << r << endl;
    return 0;
}
