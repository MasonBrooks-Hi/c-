#include <iostream>
#include <algorithm>
using namespace std;
int idx(int x, int y) {
    if (y == 1) return x - 1;                 // bottom row, left to right, (1,1)=0..(19,1)=18
    if (x == 19) return 18 + (y - 1);         // right col, (19,2)=19..(19,19)=36
    if (y == 19) return 36 + (19 - x);        // top row, right to left, (18,19)=37..(1,19)=54
    return 54 + (19 - y);                     // left col, (1,18)=55..(1,2)=71
}
int main() {
    int x1, y1, x2, y2;
    if (cin >> x1 >> y1 >> x2 >> y2) {
        int a = idx(x1, y1), b = idx(x2, y2);
        int dist = abs(a - b);
        int ans = min(dist, 72 - dist);
        cout << ans << endl;
    }
    return 0;
}
