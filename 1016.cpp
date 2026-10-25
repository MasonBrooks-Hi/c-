#include <iostream>
using namespace std;
int main() {
    int n, a, b, c, s1 = 0, s2 = 0, s3 = 0;
    if (!(cin >> n)) return 0;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        s1 += a; s2 += b; s3 += c;
    }
    cout << s1 << " " << s2 << " " << s3 << " " << s1 + s2 + s3 << "\n";
    return 0;
}
