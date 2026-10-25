#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cmath>
#include <numeric>
using namespace std;
int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    double avg = sum / (double)n;
    printf("AV=%.1f\n", avg);
    bool first = true;
    for (int i = 0; i < n; i++) if (a[i] > avg) {
        if (!first) cout << " ";
        cout << i + 1 << ":" << a[i];
        first = false;
    }
    cout << "\n";
    return 0;
}
