#include <iostream>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    while (n--) {
        long long N, M;
        cin >> N >> M;
        if (N % (M + 1) == 0)
            cout << "Lose\n";
        else
            cout << "Win\n";
    }
    return 0;
}
