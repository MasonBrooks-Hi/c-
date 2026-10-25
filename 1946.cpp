#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    double sum = 0;
    for (int i = 1; i < n - 1; i++) sum += a[i]; // 去掉一个最高、一个最低
    double avg = sum / (n - 2);
    printf("%.2f\n", avg);
    return 0;
}
