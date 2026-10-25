#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    cin.ignore(); // skip newline after n
    int totalSpaces = 0;
    vector<string> cleaned;
    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        string c;
        for (char ch : line) {
            if (ch == ' ') totalSpaces++;
            else c += ch;
        }
        cleaned.push_back(c);
    }
    cout << totalSpaces << "\n";
    for (auto &s : cleaned) cout << s << "\n";
    return 0;
}
