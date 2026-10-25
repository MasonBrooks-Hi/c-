#include <iostream>
#include <string>
using namespace std;
int main() {
    string line;
    getline(cin, line);
    size_t p1 = line.find(',');
    size_t p2 = line.find(',', p1 + 1);
    string S = line.substr(0, p1);
    string S1 = line.substr(p1 + 1, p2 - p1 - 1);
    string S2 = line.substr(p2 + 1);
    size_t pos1 = S.find(S1);
    size_t pos2 = S.rfind(S2);
    if (pos1 != string::npos && pos2 != string::npos &&
        (int)(pos1 + S1.size()) <= (int)pos2) {
        cout << (int)pos2 - (int)(pos1 + S1.size()) << "\n";
    } else {
        cout << -1 << "\n";
    }
    return 0;
}
