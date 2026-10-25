#include <iostream>
using namespace std;

int main() {
    int h[10];
    for (int i = 0; i < 10; i++) cin >> h[i];
    int reach;
    cin >> reach;
    int cnt = 0;
    for (int i = 0; i < 10; i++) if (h[i] <= reach + 30) cnt++;
    cout << cnt << endl;
    return 0;
}
