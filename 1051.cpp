#include <iostream>
using namespace std;
int main() {
    int h, w;
    char ch;
    int solid;
    if (!(cin >> h >> w >> ch >> solid)) return 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (solid || i == 0 || i == h - 1 || j == 0 || j == w - 1) cout << ch;
            else cout << " ";
        }
        cout << "\n";
    }
    return 0;
}
