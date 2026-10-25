#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cmath>
#include <numeric>
using namespace std;
int main() {
    double sum = 0, x;
    for (int i = 0; i < 12; i++) {
        cin >> x;
        sum += x;
    }
    double avg = sum / 12.0;
    printf("$%.2f\n", avg);
    return 0;
}
