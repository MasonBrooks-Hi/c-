#include <iostream>
#include <string>
using namespace std;

void gen(int remain, int mn, string prefix) {
    if (remain >= mn) {
        cout << prefix << remain << "\n";
    }
    for (int i = mn; i < remain; i++) {
        gen(remain - i, i, prefix + to_string(i) + "+");
    }
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    for (int i = 1; i < n; i++) {
        gen(n - i, i, to_string(i) + "+");
    }
    return 0;
}
