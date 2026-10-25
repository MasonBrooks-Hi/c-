#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main() {
    int a, b, c;
    if (!(cin >> a >> b >> c)) return 0;
    if (a + b > c && a + c > b && b + c > a) {
        double p = (a + b + c) / 2.0;
        double area = sqrt(p * (p - a) * (p - b) * (p - c));
        printf("%.2f\n", area);
    } else {
        cout << "Can't\n";
    }
    return 0;
}
