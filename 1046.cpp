#include <iostream>
using namespace std;
int main() {
    int M, N, X;
    if (!(cin >> M >> N >> X)) return 0;
    int combat = N;
    while (true) {
        int need = (M + combat - 1) / combat;
        if (X < need) break;
        if (M / combat == 0) break;
        X -= need;
        combat += M / combat;
    }
    cout << combat << "\n";
    return 0;
}
