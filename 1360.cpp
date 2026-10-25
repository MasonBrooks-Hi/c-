#include <iostream>
#include <string>
using namespace std;

void hanoi(int n, char src, char dst, char aux) {
    if (n == 1) {
        cout << src << "->" << 1 << "->" << dst << "\n";
        return;
    }
    hanoi(n - 1, src, aux, dst);
    cout << src << "->" << n << "->" << dst << "\n";
    hanoi(n - 1, aux, dst, src);
}

int main() {
    int n;
    string a, b, c;
    if (!(cin >> n >> a >> b >> c)) return 0;
    hanoi(n, a[0], b[0], c[0]);
    return 0;
}
