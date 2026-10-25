#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(1, 1);
    for (int i = 0; i < n; i++) {
        int carry = 0;
        for (int j = 0; j < (int)a.size(); j++) {
            int p = a[j] * 2 + carry;
            a[j] = p % 10;
            carry = p / 10;
        }
        while (carry) { a.push_back(carry % 10); carry /= 10; }
    }
    for (int i = (int)a.size() - 1; i >= 0; i--) cout << a[i];
    cout << endl;
    return 0;
}
