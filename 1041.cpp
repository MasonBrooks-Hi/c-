#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    int n;
    if (!(cin >> n)) return 0;
    double q = 2, p = 1, sum = 0;
    for (int i = 0; i < n; i++) {
        sum += q / p;
        double nq = q + p;
        double np = q;
        q = nq; p = np;
    }
    printf("%.4f\n", sum);
    return 0;
}
