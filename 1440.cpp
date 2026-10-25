#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    if (!(cin >> n)) return 0;
    vector<double> v(n);
    int maxi = 0, mini = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] > v[maxi]) maxi = i;
        if (v[i] < v[mini]) mini = i;
    }
    vector<double> rest;
    for (int i = 0; i < n; i++)
        if (i != maxi && i != mini) rest.push_back(v[i]);
    double sum = 0;
    for (double x : rest) sum += x;
    double avg = sum / (n - 2);
    double err = 0;
    for (double x : rest) {
        double d = fabs(x - avg);
        if (d > err) err = d;
    }
    printf("%.2lf %.2lf\n", avg, err);
    return 0;
}
