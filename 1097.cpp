#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    for (char& c : s) {
        if (c == 'A') c = 'T';
        else if (c == 'T') c = 'A';
        else if (c == 'G') c = 'C';
        else if (c == 'C') c = 'G';
    }
    cout << s << endl;
    return 0;
}
