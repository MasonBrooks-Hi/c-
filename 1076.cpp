#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[100];
    for (int i = 0; i < n; i++) cin >> a[i];
    int m;
    cin >> m;
    int cnt = 0;
    for (int i = 0; i < n; i++) if (a[i] == m) cnt++;
    cout << cnt << endl;
    return 0;
}
