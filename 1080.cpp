#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;
    int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a <= 18) c1++;
        else if (a <= 35) c2++;
        else if (a <= 60) c3++;
        else c4++;
    }
    cout << fixed << setprecision(2);
    cout << (double)c1 / n * 100 << "%" << endl;
    cout << (double)c2 / n * 100 << "%" << endl;
    cout << (double)c3 / n * 100 << "%" << endl;
    cout << (double)c4 / n * 100 << "%" << endl;
    return 0;
}
