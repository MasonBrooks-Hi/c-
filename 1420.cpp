#include <iostream>
#include <set>
using namespace std;

int cubeSum(int x) {
    int s = 0;
    while (x > 0) {
        int d = x % 10;
        s += d * d * d;
        x /= 10;
    }
    return s % 1000;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int v;
    if (!(cin >> v)) return 0;
    set<int> visited;
    while (true) {
        int nxt = cubeSum(v);
        if (nxt == v) {
            cout << v << "\n";
            return 0;
        }
        if (visited.count(v)) {
            cout << "error\n";
            return 0;
        }
        visited.insert(v);
        v = nxt;
    }
    return 0;
}
