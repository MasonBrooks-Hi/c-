#include <iostream>
using namespace std;

int main() {
    int L, M;
    cin >> L >> M;
    bool tree[10001];
    for (int i = 0; i <= L; i++) tree[i] = true;
    for (int i = 0; i < M; i++) {
        int s, e;
        cin >> s >> e;
        if (s > e) { int t = s; s = e; e = t; }
        for (int j = s; j <= e; j++) tree[j] = false;
    }
    int cnt = 0;
    for (int i = 0; i <= L; i++) if (tree[i]) cnt++;
    cout << cnt << endl;
    return 0;
}
