#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    double h;
    if (!(cin >> h)) return 0;
    double dist = h;
    double cur = h;
    for (int i = 1; i < 10; i++) { cur /= 2; dist += 2 * cur; }
    double rebound = h / 1024.0;
    printf("%.4f\n", dist);
    printf("%.7f\n", rebound);
    return 0;
}
