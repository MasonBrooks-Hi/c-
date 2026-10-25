#include <iostream>
#include <string>
using namespace std;

int main() {
    string line;
    getline(cin, line);
    if (!line.empty() && line.back() == '\r') line.pop_back();
    size_t p = line.find(',');
    if (p == string::npos) {
        cout << line << '\n';
        return 0;
    }
    string a = line.substr(0, p);
    string b = line.substr(p + 1);
    cout << b << ',' << a << '\n';
    return 0;
}
