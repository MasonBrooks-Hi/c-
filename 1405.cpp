#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x >= 1 && x <= 100) a.push_back(x);
    }
    int cnt = (int)a.size();
    double sum1 = 0;
    for (int x : a) sum1 += x;
    double avg1 = sum1 / cnt;

    sort(a.begin(), a.end());
    int remove = (int)(cnt * 0.1 + 0.5); // round half up
    double sum2 = 0;
    int cnt2 = 0;
    for (int i = remove; i < cnt - remove; i++) { sum2 += a[i]; cnt2++; }
    double avg2 = (cnt2 > 0) ? sum2 / cnt2 : 0;

    printf("%.2f\n%.2f\n", avg1, avg2);
    return 0;
}
