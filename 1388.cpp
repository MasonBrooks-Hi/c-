#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
    string s;
    if (!(cin >> s)) return 0;
    queue<char> q;
    for (char c : s) q.push(c);
    int cnt = 1;
    string out;
    while (!q.empty()) {
        char c = q.front(); q.pop();
        if (cnt == 1) out += c;
        else q.push(c);
        cnt = 3 - cnt; // toggle between 1 and 2
    }
    cout << out << "\n";
    return 0;
}
