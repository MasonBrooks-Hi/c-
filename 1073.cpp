#include <iostream>
using namespace std;

int main() {
    int a, b;
    char op;
    cin >> a >> b >> op;
    if (op == '+') cout << a + b << endl;
    else if (op == '-') cout << a - b << endl;
    else if (op == '*') cout << a * b << endl;
    else if (op == '/') {
        if (b == 0) cout << "Divided by zero!\n";
        else cout << a / b << endl;
    } else {
        cout << "Invalid operator!\n";
    }
    return 0;
}
