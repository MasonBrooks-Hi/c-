#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    if (!(cin >> T)) return 0;
    const int K = 15;
    __int128 P = 1;
    for (int i = 0; i < K; i++) P *= 20;
    while (T--) {
        int M;
        cin >> M;
        int depth = 0;
        __int128 N = 0;
        for (int i = 0; i < M; i++) {
            string s;
            cin >> s;
            if (s == "IN") {
                depth++;
            } else if (s == "OUT") {
                depth--;
            } else {
                long long S;
                cin >> S;
                int e = K - (depth - 1);
                if (e < 0) e = 0;
                __int128 p = 1;
                for (int j = 0; j < e; j++) p *= 20;
                N += (__int128)(3 * S) * p;
            }
        }
        long long ans = (long long)(N / P);
        cout << ans << "\n";
    }
    return 0;
}
