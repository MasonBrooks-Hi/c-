#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    if (!(cin >> N >> M)) return 0;
    vector<int> lamp(N + 1, 1); // 1 = on
    for (int k = 1; k <= M; k++) {
        for (int i = k; i <= N; i += k)
            lamp[i] ^= 1;
    }
    bool first = true;
    for (int i = 1; i <= N; i++) {
        if (lamp[i] == 0) {
            if (!first) cout << ",";
            cout << i;
            first = false;
        }
    }
    cout << "\n";
    return 0;
}
