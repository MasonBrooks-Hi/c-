#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n > 0) cout << "positive\n";
    else if (n == 0) cout << "zero\n";
    else cout << "negative\n";
    return 0;
}
