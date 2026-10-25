#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cmath>
#include <numeric>
using namespace std;
int main() {
    double f;
    if (!(cin >> f)) return 0;
    double c = (f - 32) * 5.0 / 9.0;
    printf("%.4f\n", c);
    return 0;
}
