#include <iostream>
#include <string>
#include <set>
#include <sstream>
using namespace std;
int main() {
    string line;
    if (cin >> ws) {
        getline(cin, line);
        stringstream ss(line);
        set<string> words;
        string w;
        while (ss >> w) words.insert(w);
        for (auto& s : words) cout << s << "\n";
    }
    return 0;
}
