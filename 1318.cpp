#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    int n;
    if (cin >> n) {
        int h = n / 3600;
        int m = (n % 3600) / 60;
        int s = n % 60;
        printf("%02d:%02d:%02d\n", h, m, s);
    }
    return 0;
}
