#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long a[1000], b[1000];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    long long s = 0;
    for (int i = 0; i < n; i++) s += a[i] * b[i];
    cout << s << endl;
    return 0;
}
