#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    vector<int> v(3);
    if (cin >> v[0] >> v[1] >> v[2]) {
        sort(v.begin(), v.end(), greater<int>());
        cout << v[0] << " " << v[1] << " " << v[2] << endl;
    }
    return 0;
}
