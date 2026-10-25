#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    double sum = 0;
    long long x;
    while (cin >> x) {
        if (x == 0) break;
        sum += x;
    }
    if (sum > 100) sum = (sum - 100) * 0.9 + 100;
    printf("%.3f\n", sum);
    return 0;
}
