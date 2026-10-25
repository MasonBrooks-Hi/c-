#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(1, 1); // base 10000
    for (int f = 2; f <= n; f++) {
        long long carry = 0;
        for (int j = 0; j < (int)a.size(); j++) {
            long long p = (long long)a[j] * f + carry;
            a[j] = (int)(p % 10000);
            carry = p / 10000;
        }
        while (carry) { a.push_back((int)(carry % 10000)); carry /= 10000; }
    }
    cout << a.back();
    for (int i = (int)a.size() - 2; i >= 0; i--) {
        if (a[i] < 1000) cout << 0;
        if (a[i] < 100) cout << 0;
        if (a[i] < 10) cout << 0;
        cout << a[i];
    }
    cout << endl;
    return 0;
}
