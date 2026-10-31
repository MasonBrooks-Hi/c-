#include <iostream>
using namespace std;

int main() {
    int cnt = 0;
    char c;
    while (cin.get(c)) {
        if (c != ' ' && c != '\n' && c != '\r' && c != '\t') cnt++;
    }
    cout << cnt << '\n';
    return 0;
}
