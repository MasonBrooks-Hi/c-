#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string A, B;
    if (!(cin >> A >> B)) return 0;
    int best = 0;
    int lim = min(A.length(), B.length());
    for (int L = lim; L >= 1; L--) {
        if (A.substr(0, L) == B.substr(B.length() - L, L)) { best = L; break; }
    }
    for (int L = lim; L >= 1; L--) {
        if (B.substr(0, L) == A.substr(A.length() - L, L)) { if (L > best) best = L; break; }
    }
    cout << best << "\n";
    return 0;
}
