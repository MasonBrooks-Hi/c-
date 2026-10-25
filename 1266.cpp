#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int k;
    if (!(cin >> k)) return 0;
    double total = 95.0 * k;
    if (total >= 300) total *= 0.85;
    printf("%.2f\n", total);
    return 0;
}
