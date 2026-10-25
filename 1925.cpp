#include <iostream>
using namespace std;

bool allowed[10];

bool digitsOK(int x, int len) {
    if (x <= 0) return false;
    int cnt = 0;
    while (x) {
        if (!allowed[x % 10]) return false;
        x /= 10;
        cnt++;
    }
    return cnt == len;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        allowed[d] = true;
    }
    long long count = 0;
    for (int a = 1; a <= 9; a++)
        for (int b = 0; b <= 9; b++)
            for (int c = 0; c <= 9; c++) {
                if (!allowed[a] || !allowed[b] || !allowed[c]) continue;
                int abc = a * 100 + b * 10 + c;
                for (int d = 1; d <= 9; d++)
                    for (int e = 0; e <= 9; e++) {
                        if (!allowed[d] || !allowed[e]) continue;
                        int de = d * 10 + e;
                        int p = abc * e, q = abc * d, r = abc * de;
                        if (!digitsOK(p, 3)) continue;
                        if (!digitsOK(q, 3)) continue;
                        if (!digitsOK(r, 4)) continue;
                        count++;
                    }
            }
    cout << count << '\n';
    return 0;
}
