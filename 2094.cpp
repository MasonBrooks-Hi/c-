#include <iostream>
using namespace std;

int main() {
    double x;
    if (!(cin >> x)) return 0;
    double dist = 0, step = 2.0;
    int cnt = 0;
    while (dist < x) {
        dist += step;
        step *= 0.98;
        cnt++;
    }
    cout << cnt << '\n';
    return 0;
}
