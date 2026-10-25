#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    double s = 0;
    for (int i = 0; i < n; i++) {
        double a;
        cin >> a;
        s += a;
    }
    if (s > 100) s = (s - 100) * 0.9 + 100;
    printf("%.2f\n", s);
    return 0;
}
