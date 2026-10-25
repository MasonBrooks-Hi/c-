#include <iostream>
using namespace std;
int main() {
    int x, y, z;
    if (cin >> x >> y >> z) {
        long long adult[60] = {0};
        long long nv[60] = {0};
        adult[0] = 1;
        for (int t = 0; t <= z; ++t) {
            long long eggs = (t >= x) ? y * adult[t - x] : 0;
            nv[t + 2] += eggs;
            adult[t + 1] = adult[t] + nv[t + 1];
        }
        cout << adult[z] << endl;
    }
    return 0;
}
