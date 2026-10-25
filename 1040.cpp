#include <iostream>
#include <vector>
using namespace std;
int main() {
    int N, M;
    if (!(cin >> N >> M)) return 0;
    vector<int> st(N + 1, 0);
    for (int i = 2; i <= M; i++)
        for (int j = i; j <= N; j += i) st[j] ^= 1;
    bool first = true;
    for (int j = 1; j <= N; j++) {
        if (st[j] == 0) {
            if (!first) cout << ",";
            cout << j;
            first = false;
        }
    }
    cout << "\n";
    return 0;
}
