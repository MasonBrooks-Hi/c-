#include <iostream>
#include <string>
using namespace std;

int main() {
    int m, n;
    while (cin >> m >> n) {
        if (m == 0 && n == 0) break;
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            string row;
            cin >> row;
            for (char c : row)
                if (c == '*') cnt++;
        }
        cout << cnt << '\n';
    }
    return 0;
}
