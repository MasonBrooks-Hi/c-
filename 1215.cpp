#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = i + 1;
    do {
        for (int i = 0; i < n; i++) {
            if (i) cout << " ";
            cout << a[i];
        }
        cout << "\n";
    } while (next_permutation(a.begin(), a.end()));
    return 0;
}
