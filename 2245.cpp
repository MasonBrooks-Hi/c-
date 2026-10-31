#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    if (!(cin >> N)) return 0;
    double dollars = 100.0, marks = 0.0;
    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        double newMarks = max(marks, dollars * A / 100.0);
        double newDollars = max(dollars, marks * 100.0 / A);
        marks = newMarks;
        dollars = newDollars;
    }
    cout << fixed << setprecision(2) << dollars << "\n";
    return 0;
}
