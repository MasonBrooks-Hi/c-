#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n, m, k;
    if (!(cin >> n >> m >> k)) return 0;
    vector<string> letters(n), digits(m);
    for (int i = 0; i < n; i++) cin >> letters[i];
    for (int i = 0; i < m; i++) cin >> digits[i];
    for (int i = 0; i < k; i++) {
        cout << letters[i % n] << digits[i % m] << "\n";
    }
    return 0;
}
