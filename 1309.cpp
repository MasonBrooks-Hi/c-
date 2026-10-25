#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int a, b, c;
    if (cin >> a >> b >> c) {
        vector<int> v = {a, b, c};
        sort(v.begin(), v.end());
        if (v[2] - v[0] == 2) cout << "TRUE" << endl;
        else cout << "FALSE" << endl;
    }
    return 0;
}
