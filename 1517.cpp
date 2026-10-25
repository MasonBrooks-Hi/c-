#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<long long> a;
    long long x;
    while (cin >> x && x != 0) a.push_back(x);
    vector<long long> tails;
    for (long long v : a) {
        auto it = lower_bound(tails.begin(), tails.end(), v);
        if (it == tails.end()) tails.push_back(v);
        else *it = v;
    }
    cout << tails.size() << "\n";
    return 0;
}
