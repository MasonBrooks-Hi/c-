#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    double km;
    if (!(cin >> km)) return 0;
    double fee;
    if (km <= 3) fee = 8;
    else fee = 8 + (km - 3) * 1.6;
    printf("%.1f\n", fee);
    return 0;
}
