#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    if (!(cin >> N)) return 0;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    // part1: longest non-increasing subsequence
    vector<int> g1;
    for (int x : a) {
        int lo = 0, hi = (int)g1.size();
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (g1[mid] < x) hi = mid;
            else lo = mid + 1;
        }
        if (lo == (int)g1.size()) g1.push_back(x);
        else g1[lo] = x;
    }
    // part2: longest strictly increasing subsequence
    vector<int> g2;
    for (int x : a) {
        int lo = 0, hi = (int)g2.size();
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (g2[mid] >= x) hi = mid;
            else lo = mid + 1;
        }
        if (lo == (int)g2.size()) g2.push_back(x);
        else g2[lo] = x;
    }
    cout << g1.size() << '\n' << g2.size() << '\n';
    return 0;
}
