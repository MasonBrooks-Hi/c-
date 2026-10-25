#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    long long N;
    while (cin >> N && N != 0) {
        double sum = (double)N;
        for (long long d = 1; d < N; d++) {
            sum += 2.0 * (N - d) / (d + 1);
        }
        printf("%.2f\n", sum);
    }
    return 0;
}
