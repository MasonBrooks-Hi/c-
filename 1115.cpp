#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    string longest, shortest;
    size_t i = 0;
    bool first = true;
    while (i < s.size()) {
        while (i < s.size() && !isalpha((unsigned char)s[i])) i++;
        if (i >= s.size()) break;
        string w;
        while (i < s.size() && isalpha((unsigned char)s[i])) w += s[i++];
        if (first) { longest = w; shortest = w; first = false; }
        else {
            if (w.size() > longest.size()) longest = w;
            if (w.size() < shortest.size()) shortest = w;
        }
    }
    cout << longest << "\n" << shortest << "\n";
    return 0;
}
