#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int a, b, c;
    if (cin >> a >> b >> c) {
        int v[3] = {a, b, c};
        sort(v, v + 3);
        if (v[0] + v[1] <= v[2]) { cout << "no" << endl; return 0; }
        long long s1 = (long long)v[0] * v[0] + (long long)v[1] * v[1];
        long long s2 = (long long)v[2] * v[2];
        if (s1 == s2) cout << "zhijiao" << endl;
        else if (s1 < s2) cout << "dunjiao" << endl;
        else cout << "ruijiao" << endl;
    }
    return 0;
}
