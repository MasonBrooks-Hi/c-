#include <iostream>
using namespace std;

int main() {
    long long n, m;
    if (!(cin >> n >> m)) return 0;
    long long rice = n * 2500;
    long long flour = m * 1500;
    if (rice > flour) cout << "yes " << (rice - flour) << "\n";
    else if (rice < flour) cout << "no " << (flour - rice) << "\n";
    else cout << "same\n";
    return 0;
}
