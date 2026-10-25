#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int w;
    char ch;
    cin >> w >> ch;
    int cost = 8;
    if (w > 1000) {
        int extra = (int)ceil((double)(w - 1000) / 500.0);
        cost += extra * 4;
    }
    if (ch == 'y') cost += 5;
    cout << cost << endl;
    return 0;
}
