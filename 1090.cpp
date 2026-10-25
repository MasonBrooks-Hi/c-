#include <iostream>
#include <vector>
using namespace std;

void add(vector<int>& a, const vector<int>& b) {
    long long carry = 0;
    if (a.size() < b.size()) a.resize(b.size(), 0);
    for (int j = 0; j < (int)a.size(); j++) {
        long long s = (long long)a[j] + (j < (int)b.size() ? b[j] : 0) + carry;
        a[j] = (int)(s % 10000);
        carry = s / 10000;
    }
    while (carry) { a.push_back((int)(carry % 10000)); carry /= 10000; }
}

int main() {
    int n;
    cin >> n;
    vector<int> fact(1, 1);
    vector<int> sum(1, 1); // 1!
    for (int f = 2; f <= n; f++) {
        long long carry = 0;
        for (int j = 0; j < (int)fact.size(); j++) {
            long long p = (long long)fact[j] * f + carry;
            fact[j] = (int)(p % 10000);
            carry = p / 10000;
        }
        while (carry) { fact.push_back((int)(carry % 10000)); carry /= 10000; }
        add(sum, fact);
    }
    cout << sum.back();
    for (int i = (int)sum.size() - 2; i >= 0; i--) {
        if (sum[i] < 1000) cout << 0;
        if (sum[i] < 100) cout << 0;
        if (sum[i] < 10) cout << 0;
        cout << sum[i];
    }
    cout << endl;
    return 0;
}
