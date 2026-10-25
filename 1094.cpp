#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string a, b;
        cin >> a >> b;
        if (a == b) cout << "Tie\n";
        else if ((a == "Rock" && b == "Scissors") ||
                 (a == "Scissors" && b == "Paper") ||
                 (a == "Paper" && b == "Rock")) cout << "Player1\n";
        else cout << "Player2\n";
    }
    return 0;
}
