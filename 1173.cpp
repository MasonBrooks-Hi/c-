#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main() {
    double xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;
    double d = sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));
    printf("%.3lf\n", d);
    return 0;
}
