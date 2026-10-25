#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    char c;
    int n;
    float m;
    double f;
    if (!(cin >> c >> n >> m >> f)) return 0;
    printf("%c %d %.6f %.6f\n", c, n, (double)m, f);
    return 0;
}
