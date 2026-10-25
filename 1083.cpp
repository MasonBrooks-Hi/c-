#include <iostream>
using namespace std;

int main() {
    int N, NA, NB;
    cin >> N >> NA >> NB;
    int A[100], B[100];
    for (int i = 0; i < NA; i++) cin >> A[i];
    for (int i = 0; i < NB; i++) cin >> B[i];
    int wa = 0, wb = 0;
    for (int i = 0; i < N; i++) {
        int a = A[i % NA], b = B[i % NB];
        if (a == b) continue;
        if ((a == 0 && b == 2) || (a == 2 && b == 5) || (a == 5 && b == 0)) wa++;
        else wb++;
    }
    if (wa > wb) cout << "A\n";
    else if (wb > wa) cout << "B\n";
    else cout << "draw\n";
    return 0;
}
