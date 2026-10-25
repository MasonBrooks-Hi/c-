#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    double w;
    if (!(cin >> w)) return 0;
    double fee = (w <= 20) ? w * 1.68 : w * 1.98;
    printf("%.2f\n", fee);
    return 0;
}
