#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    char a, b;
    cin >> s >> a >> b;
    for (char& c : s) if (c == a) c = b;
    cout << s << endl;
    return 0;
}
