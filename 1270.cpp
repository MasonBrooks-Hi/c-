#include <iostream>
#include <string>
#include <vector>
using namespace std;

string mul(const string& a, const string& b) {
    if (a == "0" || b == "0") return "0";
    int n = a.size(), m = b.size();
    vector<int> res(n + m, 0);
    for (int i = n - 1; i >= 0; --i) {
        int x = a[i] - '0';
        for (int j = m - 1; j >= 0; --j) {
            int y = b[j] - '0';
            int p = i + j + 1;
            int s = x * y + res[p];
            res[p] = s % 10;
            res[p - 1] += s / 10;
        }
    }
    string out;
    size_t k = 0;
    while (k < res.size() - 1 && res[k] == 0) ++k;
    for (; k < res.size(); ++k) out.push_back(res[k] + '0');
    return out;
}

int main() {
    string a, b;
    if (cin >> a >> b) {
        cout << mul(a, b) << endl;
    }
    return 0;
}
